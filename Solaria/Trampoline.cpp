#include "Trampoline.h"

Trampoline::Trampoline() {
	TextTramp.loadFromFile("Carre-bleu.jpg");
	SpTramp.setTexture(TextTramp);
	SpTramp.setPosition({ 1500,500 });
}

void Trampoline::draw(RenderWindow& window) {
	window.draw(SpTramp);
}

void Trampoline::update(float deltatime) {

}