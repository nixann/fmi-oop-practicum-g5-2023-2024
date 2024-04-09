#include <iostream>
#include <cstring>
#include <fstream>

class Ingredient {
  int id;
  float quantity;
  char name[30];

public:
  Ingredient(int id, float quantity, const char* name);
  Ingredient();

  const int get_id() const;
  const float get_quantity() const;
  const char* get_name() const;

  void write_to_file(const char* filename);
  void read_from_file(const char* filename);
};

Ingredient::Ingredient() { }

Ingredient::Ingredient(int id, float quantity, const char* name) : id(id), quantity(quantity) {
  strcpy(this->name, name);
}

const int Ingredient::get_id() const {
  return this->id;
}

const float Ingredient::get_quantity() const {
  return this->quantity;
}

const char* Ingredient::get_name() const {
  return this->name;
}

void Ingredient::write_to_file(const char* filename) {
  std::ofstream o_file;

  o_file.open(filename, std::ios::binary);

  o_file.write((char*) this, sizeof(*this));

  o_file.close();
}

void Ingredient::read_from_file(const char* filename) {
  std::ifstream i_file;

  i_file.open(filename, std::ios::binary);

  i_file.read((char*) this, sizeof(*this));

  i_file.close();
}

class Recipe {
  char* name;
  Ingredient* ingredients;
  int ingredients_count;

  void do_copy(Recipe const& other);
  void do_delete();

public:
  Recipe(Recipe const& other);
  Recipe(Recipe && other);
  Recipe& operator=(Recipe const& other);
  Recipe& operator=(Recipe && other);
  ~Recipe();
  Recipe(const char* filename, const char* recipe_name);

  const int get_ingredients_count() const;
  const Ingredient get_ingredient_at(const unsigned index) const;

  void write_to_file(const char* filename);
};

const int Recipe::get_ingredients_count() const {
  return this->ingredients_count;
}

const Ingredient Recipe::get_ingredient_at(const unsigned index) const {
  if (index >= this->ingredients_count) {
    throw "Invalid index";
  }

  return this->ingredients[index];
}

void Recipe::do_copy(Recipe const& other) {
  this->name = new char[strlen(other.name)];
  strcpy(this->name, other.name);

  this->ingredients = new Ingredient[other.get_ingredients_count()];
  for (int i = 0; i < other.get_ingredients_count(); i++) {
    Ingredient other_ingredient = other.get_ingredient_at(i);
    this->ingredients[i] = Ingredient(other_ingredient.get_id(), other_ingredient.get_quantity(), other_ingredient.get_name());
  }

  this->ingredients_count = other.get_ingredients_count();
}

void Recipe::do_delete() {
  delete[] this->name;
  delete[] this->ingredients;
}

Recipe::Recipe(Recipe const& other) {
  this->do_copy(other);
}

Recipe::Recipe(Recipe && other) {
  this->name = other.name;
  this->ingredients = other.ingredients;

  other.name = nullptr;
  other.ingredients = nullptr;
}

Recipe& Recipe::operator=(Recipe const& other) {
  if (this != &other) {
    this->do_delete();
    this->do_copy(other);
  }

  return *this;
}

Recipe& Recipe::operator=(Recipe && other) {
  if (this != &other) {
    this->do_delete();
    this->name = other.name;
    this->ingredients = other.ingredients;

    other.name = nullptr;
    other.ingredients = nullptr;
  }

  return *this;
}

Recipe::~Recipe() {
  this->do_delete();
}

Recipe::Recipe(const char* filename, const char* recipe_name) {
  this->name = new char[strlen(recipe_name)];

  strcpy(this->name, recipe_name);

  std::ifstream i_file;

  i_file.open(filename, std::ios::binary);

  Ingredient temp_ing;

  int ingredients_count = 0;
  while (i_file.read((char*) &temp_ing, sizeof(temp_ing))) {
    ingredients_count++;
  }

  i_file.clear();
  i_file.seekg(0, std::ios::beg);

  this->ingredients_count = ingredients_count;

  this->ingredients = new Ingredient[this->ingredients_count];
  for (int i = 0; i < this->ingredients_count; i++) {
    i_file.read((char*) &temp_ing, sizeof(temp_ing));
    this->ingredients[i] = temp_ing;
  }

  i_file.close();
}

void Recipe::write_to_file(const char* filename) {
  std::ofstream o_file;

  o_file.open(filename);

  o_file << "Име: " << this->name << std::endl;

  for (int i = 0; i < this->ingredients_count; i++) {
    o_file << "- " << this->ingredients[i].get_name() << " " << this->ingredients[i].get_quantity() << "g" << std::endl;
  }

  o_file.close();
}


void seed_ingredients() {
  Ingredient i1 = Ingredient(1, 100, "rice");
  Ingredient i2 = Ingredient(2, 200, "beef mince");
  Ingredient i3 = Ingredient(3, 50, "onions");
  Ingredient i4 = Ingredient(4, 30, "garlic");

  std::ofstream o_file;

  o_file.open("ingredients.data", std::ios::binary);

  o_file.write((char*) &i1, sizeof(i1));
  o_file.write((char*) &i2, sizeof(i2));
  o_file.write((char*) &i3, sizeof(i3));
  o_file.write((char*) &i4, sizeof(i4));

  o_file.close();
}

int main() {
  seed_ingredients();

  Recipe r = Recipe("ingredients.data", "Rice with beef");

  Recipe r2 = r;

  r2.write_to_file("recipe.txt");

  return 0;
}