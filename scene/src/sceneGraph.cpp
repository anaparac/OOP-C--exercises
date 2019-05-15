#include <iterator>
#include "sceneGraph.h"
// Implementacija



void SceneNode::setParent(SceneNode *roditelj){
    parent = roditelj;
}



void PlaneNode::addComponent(SceneNode::Ptr pnode)
{
    pnode->setParent( (SceneNode*)(this) );
    mChildren.push_back(std::move(pnode));
}


void PlaneNode::removeComponent(const std::string &name)
{

    for ( auto it = mChildren.begin(); it != mChildren.end(); it = std::next(it,1)){
        if ( (*it)->getName() == name ){
            addChildren((*it)->getChildren());
            for ( auto it = mChildren.begin(); it != mChildren.end(); it = std::next(it,1)){
                if ( (*it)->getName() == name ){
                    mChildren.erase(it);
                    break;
                }
            }
            break;
        }
        else {
            (*it)->removeComponent(name);
        }
    }
}


void BackgrNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite);
}


void PlaneNode::update(sf::Time dt)
{

    if ( mType == Plane_t::Eagle )
            move( mVelocity );

}


void PlaneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);

    for ( auto it = mChildren.begin(); it != mChildren.end(); it = std::next(it,1)){
        (*it)->draw(target, states);
    }
}


void PlaneNode::addChildren(std::list<SceneNode::Ptr> &&mChildren_)
{
    mChildren.merge( mChildren_);
}


PlaneNode::PlaneNode(std::string name, std::string sprite_path, Plane_t type, sf::Vector2f pozicija) : SceneNode(name)
{
    mType = type;
    if ( !mTexture_plane.loadFromFile(sprite_path) )
        throw std::runtime_error("Plane loading error");

    mSprite.setTexture(mTexture_plane);
    auto velicina = mTexture_plane.getSize();

    mSprite.setOrigin(velicina.x/2, velicina.y/2);
    move(pozicija);

    setVelocity(0.0,0.0);
}


BackgrNode::BackgrNode(std::__cxx11::string backg_path)
{
    if ( !mTexture.loadFromFile(backg_path) )
        throw std::runtime_error("Background loading error");
    mTexture.setRepeated(true);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect({0,0,700,700});
}
