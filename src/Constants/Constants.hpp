#pragma once

namespace constants {
  const int kScreenWidth = 1920;
  const int kScreenHeight = 1080;

  const int kSpriteSize = 64;
  // Sprite Size.
  const int kSS = kSpriteSize;

  const sf::Vector2<int> kSpriteSizeVector(kSS, kSS);
  // Sprite Size Vector
  const sf::Vector2<int> kSSV = kSpriteSizeVector;

  const int kDefaultMapSize = 40;

  // Mouse map moving and scaling.
  const int kMouseBorderWidth = 30;
  const int kMouseBorderHeight = 30;
  const float kMapMovePerFrame = 2.f;
  // there's little MouseBoardMismatch mismatch on Windows 10.
  const sf::Vector2<int> kMouseBorderError(8, 40);
  const float kMapScalePerScroll = 0.01f;
} // namespace constants.