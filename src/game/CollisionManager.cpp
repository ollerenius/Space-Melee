#include "CollisionManager.h"

#include <iostream>

CollisionManager::CollisionManager(std::vector<MapObject*>* mapObjects) :
    _mapObjects(mapObjects) {
}

void CollisionManager::checkCollisions() {
    for (unsigned int i = 0; i < _mapObjects->size() - 1; ++i) {
        MapObject* temp1 = _mapObjects->at(i);
        MapObject* temp2 = _mapObjects->at(i + 1);
        for (unsigned int j = 0; j < temp1->getHitboxes().size(); ++j) {
            for (unsigned int k = 0; k < temp2->getHitboxes().size(); ++k) {
                Hitbox* hb1 = temp1->getHitboxes().at(j);
                Hitbox* hb2 = temp2->getHitboxes().at(k);
                if (hitbox_collision(hb1, temp1->getX(), temp1->getY(), hb2, temp2->getX(), temp2->getY())) {
                    // If collision of hitboxes
                    temp1->onCollision(hb1, hb2);
                    temp2->onCollision(hb2, hb1);
                }
            }
        }

    }
}

void CollisionManager::GameUpdated() {
    checkCollisions();
}
