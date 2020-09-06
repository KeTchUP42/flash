//
// Created by roman on 24.08.2020.
//

#include "BaseTextureManager.h"
#include "../../../general/exceptions/custom/TextureCanNotBeLoaded.h"

std::shared_ptr<sf::Texture> Managers::BaseTextureManager::load(const std::string &filename, const sf::Rect<int> &area) const {
    std::shared_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(_textureDirectory + "/" + filename, area))
        throw PreferredExceptions::TextureCanNotBeLoaded("Texture " + filename + " cannot be loaded.");

    return std::move(texture);
}
