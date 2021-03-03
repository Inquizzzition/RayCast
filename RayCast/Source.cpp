#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Vec3 {
    double x, y, z;
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vec3 operator + (const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator - (const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator * (double d) const { return Vec3(x * d, y * d, z * d); }
    Vec3 operator / (double d) const { return Vec3(x / d, y / d, z / d); }
    Vec3 normalize() const {
        double mg = sqrt(x * x + y * y + z * z);
        return Vec3(x / mg, y / mg, z / mg);
    }
};
inline double dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

struct Ray {
    Vec3 o, d;
    Ray(Vec3 o, Vec3 d) : o(o), d(d) {}
};

struct Sphere {
    Vec3 c;
    double r;
    void set_c(Vec3 v) {

    };
    Sphere(Vec3 c, double r) : c(c), r(r) {}
    Vec3 getNormal(Vec3 pi) const { return (pi - c) / r; }
    bool intersect(Ray ray, double& t) const {
        const Vec3 o = ray.o;
        const Vec3 d = ray.d;
        const Vec3 oc = o - c;
        const double b = 2 * dot(oc, d);
        const double c = dot(oc, oc) - r * r;
        double disc = b * b - 4 * c;
        if (disc < 1e-4) return false;
        disc = sqrt(disc);
        const double t0 = -b - disc;
        const double t1 = -b + disc;
        t = (t0 < t1) ? t0 : t1;
        return true;
    }
};

void clamp255(Vec3& col) {
    col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
    col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
    col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {

    const int H = 600;
    const int W = 600;

    const Vec3 white(255, 255, 255);
    const Vec3 black(0, 0, 0);
    const Vec3 red(255, 0, 0);

    Sphere sphere(Vec3( 100, 100, 20), 10);
    Sphere light(Vec3(0, 0, 50), 1);
    
    sf::Vertex v;
    sf::RenderWindow w(sf::VideoMode(H, W), "RayCast");
    sf::VertexArray va(sf::Points, W * H);
    //sf::Uint8* pixels = new sf::Uint8[800 * 600 * 4];
    //sf::Image im;
    //sf::Sprite sprite;
    
    //im.create(W, H, pixels);
    double t;
    Vec3 pix_col(black);

    Vec3 cam(0,0,0);

    while (w.isOpen()) {

        sf::Event event;
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();
        }
        w.clear();
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                pix_col = black;

                const Ray ray(Vec3(cam.x+x,cam.y+y,cam.z), Vec3(0, 0, 1));
                if (sphere.intersect(ray, t)) {
                    const Vec3 pi = ray.o + ray.d * t;
                    const Vec3 L = light.c - pi;
                    const Vec3 N = sphere.getNormal(pi);
                    const double dt = dot(L.normalize(), N.normalize());

                    pix_col = (red + white * dt) * 0.5;
                    clamp255(pix_col);
                }
                va[y*W+x].color = (sf::Color(pix_col.x, pix_col.y, pix_col.z));
                va[y*W+x].position = sf::Vector2f(x, y);
                //pixels[x+y]
            }
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) { cam.x += 1; }
if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) { cam.x -= 1; }
if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { cam.z -= 1; }
if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) { cam.z += 1; }
        //sphere.c.x += sin(TIME_UTC)*2;
        //sphere.c.y += sin(TIME_UTC)*2; 

        w.draw(va);
        w.display();
        std::cout << "D\n ";
    }
}
