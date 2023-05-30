#ifndef CONSTANTS_202303151959_HPP
#define CONSTANTS_202303151959_HPP

namespace Constants 
{
  inline constexpr int SCREEN_HEIGHT{ 768 };
  inline constexpr float TOP_WALL{ SCREEN_HEIGHT / 2 };
  inline constexpr float BOTTOM_WALL{ -(SCREEN_HEIGHT / 2) };

  inline constexpr int SCREEN_WIDTH{ 1024 };
  inline constexpr float LEFT_WALL{ -(SCREEN_WIDTH / 2) };
  inline constexpr float RIGHT_WALL{ SCREEN_WIDTH / 2 };

  inline constexpr float PI{ 3.141593f };
}

#endif