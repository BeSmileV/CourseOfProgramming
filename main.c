#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>

typedef struct point {
    double x;
    double y;
} point;

/// вводит структуру p типа point
void inputPoint(point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

/// выводит структуру p типа point
void outputPoint(point p) {
    printf("(%.3lf; %.3lf)", p.x, p.y);
}

/// вводит массив структур p размера n типа point
void inputPoints(point *p, const size_t n) {
    for (size_t i = 0; i < n; i++)
        inputPoint(&p[i]);
}

/// выводит массив структур p размера n типа point
void outputPoints(point *p, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        outputPoint(p[i]);
        printf("\n");
    }
}

/// возвращает точку, находящуюся посередине между точками p1 и p2
point getMiddlePoint(const point p1, const point p2) {
    return (point) {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
}
/// возвращает значение 1, если точки совпадают, иначе - 0
bool isEqualPoint(point p1, point p2) {
    return fabs(p1.x - p2.x) <= DBL_EPSILON && fabs(p1.y - p2.y) <= DBL_EPSILON;
}
///возвращает значение 1, если точка p3 лежит ровно посередине между точками p1 и p2, иначе - 0
bool isPointBetween(point p1, point p2, point p3) {
    return isEqualPoint(p3, getMiddlePoint(p1, p2));
}

void swapDouble(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

///меняет значения координат x и y структуры типа point
void swapCoordinates(point *p) {
    swapDouble(&p->x, &p->y);
}

/// обменивает точки p1 и p2
void swapPoints(point *p1, point *p2) {
    point t = *p2;
    *p2 = *p1;
    *p1 = t;
}

/// возвращает расстояние между точками p1 и p2
double getDistance(point p1, point p2) {
    double distanceX = p1.x - p2.x;
    double distanceY = p1.y - p2.y;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}

/// возвращает ноль, если точки равны, положительное значение, если значение поля x первой точки больше второй или, если они равны, и значение поля y первой точки неменьше второй,  иначе - отрицательное значение.
/// returns zero if the points are equal, a positive value
/// if the value of the field x of the first point is greater than the second,
/// or if they are equal, and the value of the field y of the first point is not less than the second,
/// otherwise a negative value.
int cmp_point(const void *a, const void *b) {
    point *p1 = (point *) a;
    point *p2 = (point *) b;
    if (isEqualPoint(*p1, *p2))
        return 0;
    else if (p1->x > p2->x || p1->x == p2->x && p1->y >= p2->y)
        return 1;
    else
        return -1;
}

/// возвращает ноль, если расстояния между {0, 0} и точками равны, положительное значение
/// , если расстояние между {0, 0} первой точкой больше, иначе - отрицательное значение.
/// returns zero if the distances between {0, 0} and the points
/// are equal, a positive value if the distance between {0, 0}
/// the first point is greater, otherwise a negative value.
int cmp_pointForDistance(const void *a, const void *b) {
    point *p1 = (point *) a;
    point *p2 = (point *) b;
    double distanceP1 = getDistance(*p1, (point) {0, 0});
    double distanceP2 = getDistance(*p2, (point) {0, 0});
    if (fabs(distanceP1 - distanceP2) < DBL_EPSILON)
        return 0;
    else if (distanceP1 - distanceP2 > DBL_EPSILON)
        return 1;
    else
        return -1;
}

//#define N 3
//
//int main(){
//    point pArray[N] = {};
//
//    return 0;
//}

//int main(){
//    point p1 = {1, 2};
//    point p2 = {3, 5};
//    p1 = p2;
//
//    return 0;
//}

// Number "n"
//int main(){
//    point pointArray[]={
//            {10,11},
//            {11,9},
//            {13,4},
//    };
//    qsort(pointArray, 3, sizeof(point), cmp_pointForDistance);
//
//    outputPoints(pointArray, sizeof(pointArray) / sizeof(point));
//    return 0;
//}

//int main(){
//    point *p = (point*) malloc(sizeof(point) * 3);
//    free(p);
//    return 0;
//}

// Number "m"
//int main(){
//    point pointArray[]={
//            {1,-1},
//            {-2,-3},
//            {14,2},
//            {10,6},
//            {10,5},
//    };
//    qsort(pointArray, 5, sizeof(point), cmp_point);
//
//    outputPoints(pointArray, sizeof(pointArray) / sizeof(point));
//    return 0;
//}

typedef struct line {
    double a;
    double b;
    double c;
} line;

/// introduces a type line structure l
void inputLine(line *l) {
    scanf("%lf %lf %lf", &l->a, &l->b, &l->c);
}

/// returns a straight line along the coordinates of points
/// p1 and p2.
line getLineByPoints(point p1, point p2) {
    line line = {p2.y - p1.y, p1.x - p2.x, p1.y * p2.x
                                           - p1.x * p2.y};
    return line;
}

/// output of a line type l structure
void outputLineEquation(line line) {
    printf("%.2lfx%+.2lfy%+.2lf = 0", line.a, line.b, line.c);
}

/// returns the value 1 if the lines l1 and l2 are parallel,
/// otherwise - 0.
bool isParallel(line l1, line l2) {
    return fabs(l1.a * l2.b - l2.a * l1.b) < DBL_EPSILON;
}

/// returns the value 1 if the lines l1 and l2 are perpendicular,
/// otherwise - 0.
bool isPerpendicular(line l1, line l2) {
    return fabs(l1.a * l2.a + l1.b * l2.b) < DBL_EPSILON;
}

/// returns 1 if there are parallel lines among the data on the plane,
/// otherwise - 0.
bool hasParallelLines(line *lines, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++)
            if (isParallel(lines[i], lines[j]))
                return 1;
    }

    return 0;
}

/// returns 1 if the lines l1 and l2 are equal, otherwise - 0
bool isEqualLines(line l1, line l2) {
    return fabs(l1.a - l2.a) < DBL_EPSILON &&
           fabs(l1.b - l2.b) < DBL_EPSILON &&
           fabs(l1.c - l2.c) < DBL_EPSILON;
}

/// outputs the intersection point of lines l1 and l2.
/// If there are no intersection points – "There are no intersection points",
/// if the lines coincide - "The lines coincide".
void printIntersectionPoint(line l1, line l2) {
    if (isEqualLines(l1, l2))
        printf("The lines coincide");
    else if (isParallel(l1, l2))
        printf("There are no intersection points");
    else {
        double y = (l2.c * l1.a - l2.a * l1.c) /
                   (l2.a * l1.b - l2.b * l1.a);
        point intersectionPoint = {(-l2.b * y - l2.c) /
                                   l2.a, y};
        outputPoint(intersectionPoint);
    }
}

//int main() {
//    line l1 = {1, 2, 2};
//    line l2 = {1, 2, 4};
//    printIntersectionPoint(l1, l2);
//
//    return 0;
//
//}

// Number "d"
//int main(){
//    line l = getLineByPoints((point){1, 2}, (point){2,3});
//    outputLineEquation(l);
//
//    return 0;
//}

// Number "b"
//int main(){
//    line l = {1, 2 ,3 };
//    return 0;
//}
/// \param center - центр окружности
/// \param r - радиус
typedef struct circle {
    point center;
    double r;
} circle;

/// introduces a type circle structure a
void inputCircle(circle *a) {
    inputPoint(&a->center);
    scanf("%lf", &a->r);
}

/// enters an array a of size n of type circle
void inputCircles(circle *a, size_t n) {
    for (size_t i = 0; i < n; i++)
        inputCircle(&a[i]);
}

/// output of a circle type a structure
void outputCircle(circle a) {
    outputPoint(a.center);
    printf(" %.3lf", a.r);
}

/// output of an array a of size n of type circle
void outputCircles(circle *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        outputCircle(a[i]);
        printf("\n");
    }
}

/// returns the number of circles of an array c of size n of type circle
/// in a circle with index indexOfCircle
int getAmountInnerCircle(circle *c, size_t n, size_t indexOfCircle) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        if (c[indexOfCircle].r - getDistance(c[indexOfCircle].center, c[i].center) -
            c[i].r > -DBL_EPSILON)
            count++;

    return count - 1;
}

/// returns the circle of an array c of size n of the circle type,
/// which contains the largest number of circles
circle getCircleWithMaxAmountOfInnerCircle(circle *c, size_t n) {
    size_t indexOfPotentialCircle = 0;
    int maxAmount = getAmountInnerCircle(c, n, indexOfPotentialCircle);
    for (size_t i = 1; i < n; i++) {
        int amountNow = getAmountInnerCircle(c, n, i);
        if (amountNow > maxAmount || amountNow == maxAmount
                                     && c[i].r < c[indexOfPotentialCircle].r) {
            maxAmount = amountNow;
            indexOfPotentialCircle = i;
        }
    }

    return c[indexOfPotentialCircle];
}
/// returns 1 if the circle c1 touches the circle c2 externally, otherwise 0
bool hasOneOuterIntersection(circle c1, circle c2) {
    return fabs(getDistance(c1.center, c2.center) - c1.r - c2.r) < DBL_EPSILON;
}
/// returns 1 if circle c1 is equal to circle c2, otherwise 0
bool isEqualCircle(circle c1, circle c2) {
    return isEqualPoint(c1.center, c2.center) && fabs(c1.r - c2.r) < DBL_EPSILON;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapCircle(circle *c1, circle *c2) {
    circle t = *c1;
    *c1 = *c2;
    *c2 = t;
}

/// input an array a of size n consisting of elements
/// equal to the number of circles in a given array c of size n
void inputArrayOfInnerCircle(int *a, size_t n, circle *c) {
    for (size_t i = 0; i < n; i++)
        a[i] = getAmountInnerCircle(c, n, i);
}

/// returns 1 if all elements of array a are equal
int isEqualAmountInnerCircle(const int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] != a[i + 1])
            return 0;
    }
    return 1;
}

/// returns zero if the the radii a and b are equal,
/// a positive value if the radius a is greater than b,
/// otherwise a negative value.
int cmp_forArrayOfCircle(const void *a, const void *b) {
    circle *c1 = (circle *) a;
    circle *c2 = (circle *) b;
    if (fabs(c1->r - c2->r) < DBL_EPSILON)
        return 0;
    else if (c1->r - c2->r > DBL_EPSILON)
        return 1;
    else
        return -1;

}

/// sorts an array of circles by non-decreasing the number
/// of circles lying in it. If the number of the last
/// indicator is equal, sort by non-decreasing radius
void sortArrayOfCircle(circle *c, size_t n) {
    int a[n];
    inputArrayOfInnerCircle(a, n, c);
    if (isEqualAmountInnerCircle(a, n))
        qsort(c, n, sizeof(circle), cmp_forArrayOfCircle);
    else {
        for (size_t i = 0; i < n; i++) {
            size_t minIndex = i;
            for (size_t j = i + 1; j, n; j++)
                if (a[minIndex] > a[j])
                    minIndex = j;
            swapCircle(&c[minIndex], &c[i]);
            swap(&a[minIndex], &a[i]);
        }
    }
}

//int main() {
//    circle c[3];
//    inputCircles(c, 3);
//    outputCircle(getCircleWithMaxAmountOfInnerCircle(c, 3));
//
//    return 0;
//}

typedef struct fraction {
    int numerator;
    int denominator;
} fraction;

/// introduces a structure f, of type fraction
void inputFraction(fraction *f) {
    scanf("%d / %d", &f->numerator, &f->denominator);
}

/// introduces an array of structures f of size n
/// of type fraction
void inputFractions(fraction *f, size_t n) {
    for (size_t i = 0; i < n; i++)
        inputFraction(&f[i]);
}

/// outputs a structure f of type fraction
void outputFraction(fraction f) {
    printf("%d/%d", f.numerator, f.denominator);
}

/// outputs an array of structures f of size n
/// of type fraction
void outputFractions(fraction *f, size_t n) {
    for (size_t i = 0; i < n; i++) {
        outputFraction(f[i]);
        printf("\n");
    }
}

int min2(const int a, const int b) {
    return a < b ? a : b;
}

/// returns the largest common divisor of the
/// number a and b
int gcd(const int a, const int b) {
    int k = min2(a, b);
    while (a % k != 0 || b % k != 0)
        k--;

    return k;
}

/// returns the smallest common multiple of the
/// numbers a and b
int lcm(const int a, const int b) {
    return a * b / gcd(a, b);
}

/// reduces the fraction f
void simpleFraction(fraction *f) {
    int d = gcd(f->numerator, f->denominator);
    f->numerator /= d;
    f->denominator /= d;
}

/// returns a value equal to the multiplication of
/// two fractions f1 and f2
fraction mulFractions(fraction f1, fraction f2) {
    simpleFraction(&f1);
    simpleFraction(&f2);
    fraction a = {f1.numerator, f2.denominator};
    fraction b = {f2.numerator, f1.denominator};
    simpleFraction(&b);
    simpleFraction(&a);

    return (fraction) {a.numerator * b.numerator,
                       a.denominator * b.denominator};
}

#include <assert.h>

/// flips the fraction f
void reversFraction(fraction *f) {
    int t = f->numerator;
    f->numerator = f->denominator;
    f->denominator = t;
}

/// returns a value equal to the division of
/// two fractions f1 and f2
fraction divFraction(fraction f1, fraction f2) {
    assert(f2.numerator != 0 && f2.denominator != 0);
    reversFraction(&f2);

    return mulFractions(f1, f2);
}

/// returns a value equal to the addition of two
/// fractions f1 and f2
fraction addFraction(fraction f1, fraction f2) {
    int denominator = lcm(f1.denominator, f2.denominator);
    int numerator = f1.numerator * (denominator / f1.denominator) +
            f2.numerator * (denominator / f2.denominator);
    fraction result = {numerator, denominator};
    simpleFraction(&result);
    return result;
}

/// returns a value equal to the subtraction of two
/// fractions f1 and f2
fraction subFraction(fraction f1, fraction f2) {
    f2.numerator *= -1;
    return addFraction(f1, f2);
}

/// returns the value of the sum of fractions of an
/// array of structures f of size n of type fraction
fraction sumFractions(fraction *f, size_t n) {
    fraction sum = {0, 1};
    for (size_t i = 0; i < n; i++)
        sum = addFraction(sum, f[i]);

    return sum;
}

//int main() {
//    fraction f1 = {1 , 2};
//    fraction f2 = {4 , 3};
//    outputFraction(divFraction(f1, f2));
//
//    return 0;
//}

#define N_MARKS 5

typedef struct student {
    char surname[20];
    int marks[N_MARKS];
} student;

/// entering an array of marks of size n, in which
/// the student's grades are listed
void inputMarks(int *marks, size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &marks[i]);
}

/// entering a student structure of the student type
void inputStudent(student *s) {
    scanf("%s", s->surname);
    inputMarks(s->marks, N_MARKS);
}

/// output of the student's name of the
/// structure s of the student type
void outputStudent(student s) {
    printf("%s", s.surname);
}

/// entering an array of structures of s size
/// n type student
void inputStudents(student *s, const size_t n) {
    for (size_t i = 0; i < n; i++)
        inputStudent(&s[i]);
}

/// output of an array of structures of s
/// size n type student
void outputStudents(student *s, const size_t n) {
    for (size_t i = 0; i < n; i++) {
        outputStudent(s[i]);
        printf("\n");
    }
}
/// returns the value 0 if the student has more than one
/// unsatisfactory grade in the list, otherwise - 1
bool isGoodStudent(const student s) {
    int count = 0;
    for (size_t i = 0; i < N_MARKS; i++) {
        count += (s.marks[i] == 2);
        if (count > 1)
            return 0;
    }
    return 1;
}

/// removes students from the array of structures s
/// of the size of the student prototype who have
/// more than 1 unsatisfactory grade
void deleteStudentsWithBadMarks(student *s, size_t *n) {
    size_t iRead = 0;
    while (iRead < *n && isGoodStudent(s[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (isGoodStudent(s[iRead])) {
            s[iWrite] = s[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

//int main() {
//    size_t n;
//    scanf("%zu", &n);
//    student *s = (student*) malloc(sizeof(student) * n);
//    inputStudents(s, n);
//    deleteStudentsWithBadMarks(s, &n);
//    outputStudents(s, n);
//
//}

#define AMOUNT_OF_MARKS 5

typedef struct time{
    int hours;
    int minutes;
    int seconds;
} time;

/// introduces a time type t structure
void inputTime(time *t){
    scanf("%d:%d:%d", &t->hours, &t->minutes, &t->seconds);
}
/// outputs a time type t structure
void outputTime(time t){
    printf("%02d:%02d:%02d", t.hours, t.minutes, t.seconds);
}
/// introduces an array of structures of t size n type time
void inputArrayOfTime(time *t, const size_t n){
    for(size_t i = 0; i < n; i++)
        inputTime(&t[i]);
}
/// outputs an array of structures of t size n type time
void outputArrayOfTime(time *t, const size_t n){
    for(size_t i = 0; i < n; i++) {
        outputTime(t[i]);
        printf("\n");
    }
}
/// returns the value of time t in seconds
int getTimeInSec(time t){
    return t.seconds + t.minutes * 60 + t.hours * 3600;
}

/// returns zero if time a and b are equal, a positive value
/// if time a is greater than b, otherwise a negative value.
int cmp_Times(const void *a, const void *b) {
    time *t1 = (time *) a;
    time *t2 = (time *) b;
    int tInSec1 = getTimeInSec(*t1);
    int tInSec2 = getTimeInSec(*t2);
    if (tInSec1 == tInSec2)
        return 0;
    else if (tInSec1 > tInSec2)
        return 1;
    else
        return -1;
}

//int main(){
//    time t[AMOUNT_OF_MARKS];
//    inputArrayOfTime(t, AMOUNT_OF_MARKS);
//    qsort(t, AMOUNT_OF_MARKS, sizeof(time), cmp_Times);
//    outputArrayOfTime(t, AMOUNT_OF_MARKS);
//
//    return 0;
//}

/// returns t as h:m:s
time getTimeForStructures(const int t){
    int hours = t / 3600;
    int minutes = (t % 3600) / 60;
    int second = (t % 3600) % 60;

    return (time){hours, minutes, second};
}

/// returns the elapsed time from t1 to t2
time getPastTense(time t1, time t2){
    int divTimeInSec = getTimeInSec(t2) - getTimeInSec(t1);

    return getTimeForStructures(divTimeInSec);
}

int main(){
    time t1 = {1, 2,3};
    time t2 = {10, 12,32};

    outputTime(getPastTense(t1, t2));

    return 0;
}