#include<boost/shared_ptr.hpp>

#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Polygon_2.h>
#include<CGAL/create_straight_skeleton_from_polygon_with_holes_2.h>

#include "dump_to_eps.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel K ;

typedef K::Point_2                    Point ;
typedef CGAL::Polygon_2<K>            Polygon ;
typedef CGAL::Polygon_with_holes_2<K> Polygon_with_holes ;
typedef CGAL::Straight_skeleton_2<K>  Ss ;


typedef boost::shared_ptr<Ss> SsPtr ;

int main()
{
  Polygon_with_holes input ;
  
  std::ifstream is("bee.poly") ;
  is >> input ;
     
  SsPtr ss = CGAL::create_partial_interior_straight_skeleton_2(input,2.5);

  dump_to_eps(input,*ss,"partial_skeleton.eps");
  
  
  return 0;
}
