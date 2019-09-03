#include <cassert>
#include <iostream>
#include <random>

#include "delaunay.h"

#define REQUIRE assert
#define TEST_CASE(case, label) std::cout << label << ": " <<  case << std::endl;

int main() {

TEST_CASE( "Delaunay triangulation should be able to triangulate 3 points as double", "[DelaunayTest]" ) {
    std::vector<Vector2> points;
    points.push_back(Vector2{0.0, 0.0});
    points.push_back(Vector2{1.0, 0.0});
    points.push_back(Vector2{0.0, 1.0});
    Delaunay triangulation;
    const std::vector<Triangle> triangles = triangulation.triangulate(points);
    REQUIRE(1 == triangles.size());
    // const std::vector<Edge<double> > edges = triangulation.getEdges();
}

TEST_CASE("Delaunay triangulation should be able to handle duplicated 3 points as double", "[DelaunayTest]") {
    std::vector<Vector2> points;
    points.push_back(Vector2{0.0, 0.0});
    points.push_back(Vector2{0.0, 0.0});
    points.push_back(Vector2{1.0, 0.0});
    points.push_back(Vector2{0.0, 1.0});
    Delaunay triangulation;
    const std::vector<Triangle> triangles = triangulation.triangulate(points);
    REQUIRE(1 == triangles.size());
    // const std::vector<Edge<double> > edges = triangulation.getEdges();
}

std::default_random_engine eng(std::random_device{}());

TEST_CASE("Delaunay triangulation should be able to handle 10000 points as double", "[DelaunayTest]") {
	std::uniform_real_distribution<double> dist(0,
			std::numeric_limits<double>::max());
	constexpr size_t nb_pts = 1e4;
    std::vector<Vector2> points(nb_pts);
    for (size_t i=0; i < nb_pts; ++i)
    {
        const double x = dist(eng);
        const double y = dist(eng);
        points.at(i) = Vector2{x, y};
    }
    REQUIRE(points.size() == nb_pts);
    Delaunay triangulation;
    const std::vector<Triangle> triangles = triangulation.triangulate(points);
}

    return 0;
}

