class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        
          r = radius;
          x = x_center;
          y = y_center;
    }
    
double gen( )     
{
    double temp =(double) rand( )/ RAND_MAX;
    
    return temp;
}

  vector<double> randPoint() {
    
    double length = sqrt(gen( )) * r;
    
    double theta = gen() * 2* 3.14159;
    
    double xaxis = x + length*cos(theta);
    
    double yaxis = y + length*sin(theta);
    
    
    return vector<double>{xaxis,yaxis};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */