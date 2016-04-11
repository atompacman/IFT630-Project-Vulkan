#ifndef PLH_UIELEMENT
#define PLH_UIELEMENT

#include <alpp/Core.h>
#include <alpp/Render/Renderer.h>

class UIElement
{
public:

    UIElement(WorldCoords i_Position, WorldCoords i_Size) :
        m_Pos (i_Position),
        m_Size(i_Size)
    {};
    virtual ~UIElement() { };

    virtual void render(sptr<alpp::render::Renderer> i_Renderer) const = 0;

    bool isMouseInArea(PixelCoords i_MousePos) const
    {
        WorldCoords mouseWP(i_MousePos);
        return mouseWP.x >= m_Pos.x && mouseWP.x <= m_Pos.x + m_Size.x
            && mouseWP.y >= m_Pos.y && mouseWP.y <= m_Pos.y + m_Size.y;
    };

    WorldCoords getPosition() const { return m_Pos; };
    WorldCoords getSize()     const { return m_Size; };

    void setPositionAndSize(WorldCoords i_Pos, WorldCoords i_Size)
    {
        m_Pos  = i_Pos;
        m_Size = i_Size;
    };

protected:

    WorldCoords m_Pos;
    WorldCoords m_Size;
};

#endif // PLH_UIELEMENT