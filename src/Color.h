#ifndef COLOR_H
#define COLOR_H
#include <unordered_map>

enum Color { B = 1, I, P, E, N, D, A, W, R, O, Y, G, U, S, K, F };
static std::unordered_map<std::string, Color> colorMap{{"B", Color::B}, {"I", Color::I}, {"P", Color::P}, {"E", Color::E}, {"N", Color::N}, {"D", Color::D}, {"A", Color::A}, {"W", Color::W}, {"R", Color::R}, {"O", Color::O}, {"Y", Color::Y}, {"G", Color::G}, {"U", Color::U}, {"S", Color::S}, {"K", Color::K}, {"F", Color::F}};

#endif