## Задача

Дефинирайте абстрактен клас Shape, който има единствена чисто виртуална функция:
 * virtual float area() = 0;

Дефинирайте абстрактен клас Printable, който има единствена чисто виртуална функция:
 * virtual void print() = 0;

Дефинирайте базов клас Colorable, който има единствено поле color (низ с неограничен размер) и съответните get и set методи за color.

Дефинирайте клас Circle, който наследява класовете Shape, Printable и Colorable и освен това има поле, което пази стойността на радиуса му. Нека наследеният `print` метод отпечатва детайлите за кръга в следния формат:
`Форма: кръг, цвят: <цвят>, лице: <лице>`

Дефинирайте клас Rectangle, който наследява класовете Shape, Printable и Colorable и освен това има две полета, които пазят дължините на двете му перпендикулярни страни.
Нека наследеният `print` метод отпечатва детайлите за правоъгълника в следния формат:
`Форма: правоъгълник, цвят: <цвят>, лице: <лице>`

Дефинирайте клас ShapesContainer, който има следните полета и методи:
 * shapes - списък с неограничен размер, съдържащ **указатели** към Shape обекти.
 * Единствен конструктор, който приема статичен масив от указатели към форми и брой на подадените форми
 * void printLargest() - отпечатва детайлите за формата с най-голямо лице
