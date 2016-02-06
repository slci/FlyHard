#pragma once

#include "Entity.hpp"
#include "resource_mgmt/ResourceHolder.hpp"

namespace SFGame
{

/**
 * Forward declarations
 */
class World;
struct CommandCategory;

class PlayerAircraft: public Entity
{
public:
    enum class MovingState
    {
        eConstMoving,
        eAccelerating,
        eDecelerating
    };

public:
    explicit PlayerAircraft(const sf::Vector2f& spawnPosition,
                            const float scrollSpeed,
                            const TextureHolder& textureHolder,
                            const World& world);

	virtual CommandCategory	getCommandCategory() const override;

    void accelerate(const float vX);
    void decelerate();

    void setMoveState(MovingState state) { mState = state; }

public:
    static const float cAccelerationValue;

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void updateCurrent() override;

    void move(float offsetX, float offsetY);

private:
    MovingState mState;

    sf::Sprite mRaptor;
    sf::Sprite mShadow;
    const float cMaxVelocity;

    const World& mWorld;
};


class AircraftMover
{
public:
    AircraftMover(float vX) : mVelocity(vX) {}

    void operator() (PlayerAircraft& aircraft) const
    {
        aircraft.accelerate(mVelocity);
    }
private:
    float mVelocity;
};

} //namespace sfml_playground
