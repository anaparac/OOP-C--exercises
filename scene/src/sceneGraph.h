#ifndef SCENE_GRAPH_IS_INCLUDED
#define SCENE_GRAPH_IS_INCLUDED

#include <memory>
#include <list>
#include <string>

#include <SFML/Graphics.hpp>

enum class Plane_t{ Eagle, Raptor };

class SceneNode : public sf::Transformable, public sf::Drawable
{
    public:

        SceneNode(){}
        SceneNode(std::string name){ mName = name; parent = nullptr;}
        using Ptr = std::unique_ptr<SceneNode>;
              
        void setParent(SceneNode *roditelj );
        SceneNode* getParent(){return parent;}

        virtual void addComponent(Ptr pnode){}
        virtual void removeComponent(std::string const & name){}

        virtual void update(sf::Time dt){}
        std::string getName() const { return mName; }

        ~SceneNode(){}

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const {}
        // Implementacijski detalji

        virtual std::list<Ptr>&& getChildren(){}
        virtual void addChildren( std::list<Ptr> &&mChildren_ ){}



        //
    private:


        std::string    mName;
        SceneNode      *parent;

};


// BackgrNode služi za crtanje background-a. On se ne miče
// niti ne centriramo njegov Sprite.
class BackgrNode : public SceneNode {
    public:
      // ...
        BackgrNode(std::string backg_path);
    private:
        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const{}
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        sf::Sprite   mSprite;
        sf::Texture  mTexture;

};


// SpriteNode služi za crtanje aviona.
class  PlaneNode : public SceneNode{
    public:

        PlaneNode(std::string name_, std::string sprite_path, Plane_t type , sf::Vector2f pozicija);

        void addComponent(Ptr pnode);
        void removeComponent(std::string const & name);

    // ....

        void setVelocity(sf::Vector2f v) {mVelocity = v; }
        void setVelocity(float vx, float vy) { mVelocity.x = vx; mVelocity.y = vy; }
        sf::Vector2f getVelocity() const { return mVelocity; }

        void update(sf::Time dt);
        //std::list<Ptr> getChildren() {return mChildren;}


        std::list<Ptr>&& getChildren(){ return std::move(mChildren); }
        void addChildren( std::list<Ptr> &&mChildren_ );

        //std::list<Ptr> mChildren;
    private:
//        virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    // ........
        Plane_t      mType;
        sf::Sprite   mSprite;
        sf::Texture  mTexture_plane;
        sf::Vector2f mVelocity;
        std::list<Ptr> mChildren;

};


/*
class World : public sf::Drawable{
    public:
        World();
    private:
        void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        SceneNode mBackground;
        SceneNode mEagle;
}
*/

#endif

