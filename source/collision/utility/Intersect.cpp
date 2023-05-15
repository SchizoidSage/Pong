bool intersect(const AABB* a, const AABB* b)
{
  bool no_intersection{ 
    a->max().x < b->min().x ||
		a->max().y < b->min().y ||
		b->max().x < a->min().x ||
		b->max().y < a->min().y
  }
	// If none of these are true, they must intersect
	return !no_intersection;
}

bool intersect(const LineSegment* line_segment, const AABB* box, float& out_t, Plane& out_norm)
{
	// Vector to save all possible t values, and normals for those sides
	std::vector<std::pair<float, Plane>> t_values;
	// Test the x planes
	test_side_plane(line_segment.start().x, line_segment.end().x, box.min().x, Plane::MIN_X, t_values);
	test_side_plane(line_segment.start().x, line_segment.end().x, box.max().x, Plane::MAX_X, t_values);
	// Test the y planes
	test_side_plane(line_segment.start().y, line_segment.end().y, box.min().y, Plane::MIN_Y, t_values);
	test_side_plane(line_segment.start().y, line_segment.end().y, box.max().y, Plane::MAX_Y, t_values);
	
	// Sort the t values in ascending order
	std::sort(t_values.begin(), t_values.end(), [](
		const std::pair<float, Vector3>& a,
		const std::pair<float, Vector3>& b) {
		  return a.first < b.first;
	});
	// Test if the box contains any of these points of intersection
	glm::vec2 point;
	for (auto& t : t_values) {
		point = line_segment.point_on_segment(t.first);
		if (box.contains(point)) {
			out_t = t.first;
			out_norm = t.second;
			return true;
		}
	}

	//None of the intersections are within bounds of box
	return false;
}

bool test_side_plane(float start, float end, float negd, Plane norm, std::vector<std::pair<float, Plane>>& out)
{
	float denom{ end - start };
	if (Math::NearZero(denom)) {
		return false;
	} else {
		float numer{ -start + negd };
		float t{ numer / denom };
		// Test that t is within bounds
		if (t >= 0.0f && t <= 1.0f) {
			out.emplace_back(t, norm);
			return true;
		} else {
			return false;
		}
	}
}

Wall collides_with_wall(LineSegment line)
{
  auto end_position{ line.end() };
  Wall wall{ Wall:::NO_WALL };

  if (end_position.y < Constants::BOTTOM_WALL) {
    wall = Wall::BOTTOM_WALL;
    if (end_position.x < Constants::LEFT_WALL) {
      glm:::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        point = line.point_on_segment(i);
        if ((point.y < Constants::BOTTOM_WALL) && !(point.x < Constants::LEFT_WALL)) {
          wall = Wall::BOTTOM_WALL;
          break;
        } else if (!(point.y < Constants::BOTTOM_WALL) && (point.x < Constants::LEFT_WALL)) {
          wall = Wall::LEFT_WALL:
          break;
        } else if ((point.y < Constants::BOTTOM_WALL) && (point.x < Constants::LEFT_WALL)) {
          wall = Wall::LEFT_BOTTOM_CORNER;
          break;
        }
      }
    } else if (end_position.x > Constants::RIGHT_WALL) {
      glm:::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        point = line.point_on_segment(i);
        if ((point.y < Constants::BOTTOM_WALL) && !(point.x > Constants::RIGHT_WALL)) {
          wall = Wall::BOTTOM_WALL;
          break;
        } else if (!(point.y < Constants::BOTTOM_WALL) && (point.x > Constants::RIGHT_WALL)) {
          wall = Wall::RIGHT_WALL:
          break;
        } else if ((point.y < Constants::BOTTOM_WALL) && (point.x > Constants::RIGHT_WALL)) {
          wall = Wall::RIGHT_BOTTOM_CORNER;
          break;
        }
      }
    }
  } else if (end_position.y > Constants::TOP_WALL) {
    wall = Wall::TOP_WALL;
    if (end_position.x < Constants::LEFT_WALL) {
      glm:::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        point = line.point_on_segment(i);
        if ((point.y > Constants::TOP_WALL) && !(point.x < Constants::LEFT_WALL)) {
          wall = Wall::TOP_WALL;
          break;
        } else if (!(point.y > Constants::TOP_WALL) && (point.x < Constants::LEFT_WALL)) {
          wall = Wall::LEFT_WALL:
          break;
        } else if ((point.y > Constants::TOP_WALL) && (point.x < Constants::LEFT_WALL)) {
          wall = Wall::LEFT_TOP_CORNER;
          break;
        }
      }
    } else if (end_position.x > Constants::RIGHT_WALL) {
      glm:::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) {
        point = line.point_on_segment(i);
        if ((point.y > Constants::TOP_WALL) && !(point.x > Constants::RIGHT_WALL)) {
          wall = Wall::TOP_WALL;
          break;
        } else if (!(point.y > Constants::TOP_WALL) && (point.x > Constants::RIGHT_WALL)) {
          wall = Wall::RIGHT_WALL:
          break;
        } else if ((point.y > Constants::TOP_WALL) && (point.x > Constants::RIGHT_WALL)) {
          wall = Wall::RIGHT_TOP_CORNER;
          break;
        }
      }
    }
  } else if (end_position.x < Constants::LEFT_WALL) {
    wall = Wall::LEFT_WALL;
  } else if (end_position.x > Constants::RIGHT_WALL) {
    wall = Wall::RIGHT_WALL;
  }

  return wall;
}

Wall collides_with_wall(Capsule capsule)
{
  auto end_position{ capsule.line_end() };
  float radius{ capsule.radius() };
  Wall wall{ Wall::NO_WALL };

  if ((end_position.y - radius) < Constants::BOTTOM_WALL) { // Does capsule collide with bottom wall?
    wall = Wall::BOTTOM_WALL;
    if ((end_position.x - radius) < Constants::LEFT_WALL) { // Does capsule collide with both bottom and left wall?
      glm::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) { // Check which of the two walls capsule collides with first
        point = capsule.point_on_segment(i);
        if (!((point.y - radius) < Constants::BOTTOM_WALL) && ((point.x - radius) < Constants::LEFT_WALL)) { // It collides with left wall first
          wall = Wall::LEFT_WALL;
          break;
        } else if (((point.y - radius) < Constants::BOTTOM_WALL) && !((point.x - radius) < Constants::LEFT_WALL)) { // It collides with bottom wall first
          wall = Wall::BOTTOM_WALL;
          break;
        } else if (((point.y - radius) < Constants::BOTTOM_WALL) && ((point.x - radius) < Constants::LEFT_WALL)) { // It collides with both at the same time
          wall = Wall::LEFT_BOTTOM_CORNER;
          break;
        }
      }
    } else if ((end_position.x + radius) > Constants::RIGHT_WALL) { // Does capsule collide with both bottom and right wall?
      glm::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) { // Check which of the two walls capsule collides with first
        point = capsule.point_on_segment(i);
        if (!((point.y - radius) < Constants::BOTTOM_WALL) && ((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with right wall first
          wall = Wall::RIGHT_WALL;
          break;
        } else if (((point.y - radius) < Constants::BOTTOM_WALL) && !((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with bottom wall first
          wall = Wall::BOTTOM_WALL;
          break;
        } else if (((point.y - radius) < Constants::BOTTOM_WALL) && ((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with both at the same time
          wall = Wall::RIGHT_BOTTOM_CORNER;
          break;
        }
      }
    }
  } else if ((end_position.y + radius) > Constants::TOP_WALL) { // Does capsule collide with top wall?
    wall = Wall::TOP_WALL;
    if ((end_position.x - radius) < Constants::LEFT_WALL) { // Does capsule collide with both top and left wall?
      glm::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) { // Check which of the two walls capsule collides with first
        point = capsule.point_on_segment(i);
        if (!((point.y + radius) > Constants::TOP_WALL) && ((point.x - radius) < Constants::LEFT_WALL)) { // It collides with left wall first
          wall = Wall::LEFT_WALL;
          break;
        } else if (((point.y + radius) > Constants::TOP_WALL) && !((point.x - radius) < Constants::LEFT_WALL)) { // It collides with top wall first
          wall = Wall::TOP_WALL;
          break;
        } else if (((point.y + radius) > Constants::TOP_WALL) && ((point.x - radius) < Constants::LEFT_WALL)) { // It collides with both at the same time
          wall = Wall::LEFT_TOP_CORNER;
          break;
        }
      }
    } else if ((end_position.x + radius) > Constants::RIGHT_WALL) { // Does capsule collide with both top and right wall?
      glm::vec2 point{ };
      for (float i{ 0.0f }; i < 1; i += 0.1f) { // Check which of the two walls capsule collides with first
        point = capsule.point_on_segment(i);
        if (!((point.y + radius) > Constants::TOP_WALL) && ((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with right wall first
          wall = Wall::RIGHT_WALL;
          break;
        } else if (((point.y + radius) > Constants::TOP_WALL) && !((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with top wall first
          wall = Wall::TOP_WALL;
          break;
        } else if (((point.y + radius) > Constants::TOP_WALL) && ((point.x + radius) > Constants::RIGHT_WALL)) { // It collides with both at the same time
          wall = Wall::RIGHT_TOP_CORNER;
          break;
        }
      }
    }
  } else if ((end_position.x - radius) < Constants::LEFT_WALL) {
    wall = Wall::LEFT_WALL;
  } else if ((end_position.x + radius) > Constants::RIGHT_WALL) {
    wall = Wall::RIGHT_WALL
  }

  return wall;
}