#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};

class GradientAnimator : public emp::web::Animate
{
    emp::web::Canvas canvas{500, 500, "canvas"};
    // Instance variable that is a vector of vectors of floats
    std::vector<std::vector<float>> cells;
    double number = 0.0;
    int x = 0;
    int y = 0;
    const int num_w_boxes = 10;
    const int num_h_boxes = 10;
    const int rect_len = 50;

    // Class constructor
public:
    GradientAnimator()
    {

        doc << GetToggleButton("Toggle");
        doc << GetStepButton("Step");
        doc << canvas;

        cells.resize(num_w_boxes, std::vector<float>(num_h_boxes, 0));
    }
    void DoFrame()
    {
        canvas.Clear();

        for (int x = 0; x < num_w_boxes; x++)
        {
            for (int y = 0; y < num_h_boxes; y++)
            {
                // Use cell location in vector to set color
                // Draw a rectangle using the ColorHSV argument with the color being based on the cell vector value
                canvas.Rect(x * rect_len, y * rect_len, rect_len, rect_len,
                            emp::ColorHSV(0, 0, 1), "Black");
            }
        }

        number = number + 0.1;
        if (number > 1)
        {
            number = 0;
            x = x + 1;
        }
        if (x >= num_w_boxes)
        {
            x = 0;
            y = y + 1;
        }
        if (y >= num_h_boxes)
        {
            y = 0;
        }
        canvas.Rect(x * rect_len, y * rect_len, rect_len, rect_len, emp::ColorHSV(0, 0, number), "black");
    }
};

GradientAnimator animator;

int main()
{
    animator.Step();
}