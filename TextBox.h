#ifndef TextBox_hpp
#define TextBox_hpp

class TextBox {
    
private:
    std::string text;
    float x;
    float y;
    int length;
    float r;
    float g;
    float b;
    int Points;
   
   
    
public:
    TextBox( std::string text, float x, float y, int length, float r, float g, float b) : text(text), x(x), y(y), length(length), r(r), g(g), b(b){}
    
    TextBox() {}
    
   void draw();
};

#endif 
