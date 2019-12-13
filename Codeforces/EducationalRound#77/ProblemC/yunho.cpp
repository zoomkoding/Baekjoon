#include <cstdio>
#include <numeric>
#include <algorithm>

int main ( void ) {
   int T = 0 ;
   std :: scanf ( "%d" , & T ) ;

   for ( int i = 0 ; i < T ; i ++ ) {
      long j = 0 ;

      long r = 0 ;
      long b = 0 ;
      long k = 0 ;
      std :: scanf ( "%ld%ld%ld" , & r , & b , & k ) ;

      if ( r == b ) {
         puts ( "OBEY" ) ;
         continue ;
      } else if ( b < r ) {
         long temp = 0 ;
         temp = b ; 
         b = r ;
         r = temp ;
      }
      if ( std :: __algo_gcd ( r , b ) + ( k - 1 ) * r < b ) {
         puts ( "REBEL" ) ;
      } else {
         puts ( "OBEY" ) ;
      }
   }
   return 0 ;
}