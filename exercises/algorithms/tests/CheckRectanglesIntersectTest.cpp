/**
 * @file CheckRectanglesInterectTest.cpp
 *
 * @brief Implementation of the tests of the method that computes the intersection rectangle between two
 *        rectangles.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 */

/* INCLUDES ******************************************************************/

#include <gmock/gmock.h>

#include <cstdint>
#include <limits>
#include <string>
#include <utility>

/* USINGS ********************************************************************/

using namespace testing;

/* DEFINITIONS ***************************************************************/

static const uint8_t RECTANGLE_VERTICES = 4;

/* STATIC DECLARATIONS *******************************************************/

/**
 * @brief Structure that represents a rectangle.
 */
struct Rectangle
{
  double x;
  double y;
  double width;
  double height;
};

/* STATIC FUNCTIONS **********************************************************/

/**
 * @brief Verifies if two rectangles intersect.
 *
 * @param rectangle1 The first rectangle.
 * @param rectangle2 The second rectangle.
 *
 * @return <tt>true</tt> if the given rectangles intersect; otherwise, <tt>false</tt>.
 */
static bool
hasIntersection(const Rectangle& rectangle1, const Rectangle& rectangle2)
{
  const bool intersectsX = (rectangle1.x <= rectangle2.x + rectangle2.width)  && (rectangle1.x + rectangle1.width  >= rectangle2.x);
  const bool intersectsY = (rectangle1.y <= rectangle2.y + rectangle2.height) && (rectangle2.y + rectangle2.height >= rectangle2.y);
  return intersectsX && intersectsY;
}

/**
 * @brief Gets the rectangle product of the intersection between two rectangles.
 *
 * @param rectangle1 The first rectangle.
 * @param rectangle2 The second rectangle.
 *
 * @return The rectangle product of the intersection between the two given rectangles.
 *
 * @throw invalid_argument if the rectangles doesn't have an intersection.
 */
static Rectangle
getIntersection(const Rectangle& rectangle1, const Rectangle& rectangle2)
{
  if (hasIntersection(rectangle1, rectangle2))
  {
    const double limitX = std::min(rectangle1.x + rectangle1.width,  rectangle1.x + rectangle1.width);
    const double limitY = std::min(rectangle1.y + rectangle1.height, rectangle2.y + rectangle2.height);
    Rectangle    intersection;

    intersection.x      = std::max(rectangle1.x, rectangle2.x);
    intersection.y      = std::max(rectangle1.y, rectangle2.y);
    intersection.width  = std::abs(limitX - intersection.x);
    intersection.height = std::abs(limitY - intersection.y);

    return intersection;
  }
  else
  {
    throw std::invalid_argument("The given rectangles do not intersect.");
  }
}

/* IMPLEMENTATION ************************************************************/

TEST(CheckRectanglesIntersect, hasIntersection_intersecting_return_true)
{
  // Arrange
  const Rectangle rectangle1 = { 1 , 1, 10, 10 };
  const Rectangle rectangle2 = { 5 , 5, 10, 10 };

  // Assert
  ASSERT_THAT(hasIntersection(rectangle1, rectangle2), Eq(true));
}

TEST(CheckRectanglesIntersect, getRectangle_intersecting_return_rectangle)
{
  // Arrange
  const Rectangle rectangle1 = { 1 , 1, 10, 10 };
  const Rectangle rectangle2 = { 5 , 5, 10, 10 };

  // Act
  const Rectangle intersection = getIntersection(rectangle1, rectangle2);

  // Assert
  ASSERT_THAT(intersection.x,      Eq(5));
  ASSERT_THAT(intersection.y,      Eq(5));
  ASSERT_THAT(intersection.width,  Eq(6));
  ASSERT_THAT(intersection.height, Eq(6));
}

TEST(CheckRectanglesIntersect, getRectangle_not_intersecting_invalid_argument)
{
  // Arrange
  const Rectangle rectangle1 = { 1 ,  1, 10, 10 };
  const Rectangle rectangle2 = { 12 , 5, 10, 10 };

  // Assert
  EXPECT_THROW(getIntersection(rectangle1, rectangle2), std::invalid_argument);
}