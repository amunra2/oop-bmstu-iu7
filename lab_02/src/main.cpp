#include "../inc/vector.h"


void sum_test(void)
{
    Vector<int> a({1, 2, 3, 4, 5, 6, 7});
    Vector<int> b({1, 1, 1, 1, 1, 1, 1});
    Vector<double> e({1.3, 5.2, 7.1, 4.4, 7.1, 9.5, 1.1});

    std::cout << "\n\nOperator +" << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " + " << "5" << " = " << a + 5 << std::endl;
    std::cout << e << " + " << a << " = " << e + a << std::endl;
    std::cout << a << " + " << "1.37" << " = " << a + 1.37 << std::endl;

    std::cout << "\n\nOperator +=" << std::endl;
    std::cout << a << " += " << b << " => ";
    a += b;
    std::cout << a << std::endl;

    std::cout << a << " += " << "5" << " => ";
    a += 5;
    std::cout << a << std::endl;
}


void diff_test(void)
{
    Vector<int> a({1, 2, 3, 4, 5, 6, 7});
    Vector<int> b({1, 1, 1, 1, 1, 1, 1});
    Vector<double> e({1.3, 5.2, 7.1, 4.4, 7.1, 9.5, 1.1});

    std::cout << "\n\nOperator -" << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " - " << "5" << " = " << a - 5 << std::endl;
    std::cout << e << " - " << a << " = " << e - a << std::endl;
    std::cout << a << " - " << "1.37" << " = " << a - 1.37 << std::endl;

    std::cout << "\n\nOperator -=" << std::endl;
    std::cout << a << " -= " << b << " => ";
    a -= b;
    std::cout << a << std::endl;

    std::cout << a << " -= " << "5" << " => ";
    a -= 5;
    std::cout << a << std::endl;
}


void mult_test(void)
{
    Vector<int> a({1, 2, 3, 4, 5, 6, 7});
    Vector<int> b({2, 2, 2, 2, 2, 2, 2});
    Vector<double> e({1.3, 5.2, 7.1, 4.4, 7.1, 9.5, 1.1});

    std::cout << "\n\nOperator *" << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " * " << "5" << " = " << a * 5 << std::endl;
    std::cout << e << " * " << a << " = " << e * a << std::endl;
    std::cout << a << " * " << "1.37" << " = " << a * 1.37 << std::endl;

    std::cout << "\n\nOperator *=" << std::endl;
    std::cout << a << " *= " << b << " => ";
    a *= b;
    std::cout << a << std::endl;

    std::cout << a << " *= " << "5" << " => ";
    a *= 5;
    std::cout << a << std::endl;
}


void div_test(void)
{
    Vector<int> a({2, 4, 6, 8, 10, 12, 14});
    Vector<int> b({2, 2, 2, 2, 2, 2, 2});
    Vector<double> e({1.3, 5.2, 7.1, 4.4, 7.1, 9.5, 1.1});

    std::cout << "\n\nOperator /" << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " / " << "2" << " = " << a / 2 << std::endl;
    std::cout << e << " / " << a << " = " << e / a << std::endl;
    std::cout << a << " / " << "0.5" << " = " << a / 0.5 << std::endl;

    std::cout << "\n\nOperator /=" << std::endl;
    std::cout << a << " /= " << b << " => ";
    a /= b;
    std::cout << a << std::endl;

    std::cout << a << " /= " << "5" << " => ";
    a /= 5;
    std::cout << a << std::endl;
}


void scalar_vector_mul_test(void)
{
    Vector<int> a({2, 4, 6});
    Vector<int> b({2, 2, 2});

    std::cout << "\n\nOperator &" << std::endl;
    int res = a & b;
    std::cout << a << " & " << b << " = " << res << std::endl;

    std::cout << "\n\nOperator ^" << std::endl;
    Vector<int> vect_res = a ^ b;
    std::cout << a << " ^ " << b << " = " << vect_res << std::endl;

    std::cout << "\n\nOperator ^=" << std::endl;
    a ^= b;
    std::cout << a << " ^= " << b << " => " << a << std::endl;
}


void index_test(void)
{
    Vector<int> a({2, 4, 6, 8, 10, 12, 14});
    Vector<int> b({2, 2, 2, 2, 2, 2, 2});

    std::cout << "\n\nOperator []" << std::endl;
    std::cout << a << " => a[0]" << " = " << a[0] << std::endl;

    std::cout << "\n\nMethod Set" << std::endl;
    std::cout << a << std::endl;
    a.set(0, 5);
    std::cout << " => a.set(0, 5) => a[0] = " << a[0] << ", a = " << a << std::endl;
}


void utils_test(void)
{
    Vector<int> a({1, 1, 1, 1, 1, 1, 1});
    Vector<int> b({2, 2, 2, 2, 2, 2, 2});
    Vector<int> c(7);

    std::cout << "\n\nUtil summary()" << std::endl;
    std::cout << b.summary() << std::endl;

    std::cout << "\n\nUtil is_zero()" << std::endl;
    std::cout << c << "  Is zero? Result: " << c.is_zero() << std::endl;

    std::cout << "\n\nUtil is_single()" << std::endl;
    std::cout << a << "  Is single? Result: " << a.is_single() << std::endl;

    std::cout << "\n\nUtil get_length()" << std::endl;
    std::cout << b << "  Length: " << b.get_length<double>() << std::endl;

    Vector<int> d({2, 2, 2, 2});

    std::cout << "\n\nUtil get_norm()" << std::endl;
    std::cout << d << "  Normed: " << d.get_norm<double>() << std::endl;

    Vector<int> e({1, 2, 3, 4, 5});
    Vector<int> f({2, 4, 6, 8, 10});
    Vector<int> g({-14, 1, 1, 1, 1});

    std::cout << "\n\nUtil get_angle()" << std::endl;
    std::cout << e << " " << f << "  Angle: " << e.get_angle(g) << std::endl;

    std::cout << "\n\nUtil check_collinear()" << std::endl;
    std::cout << e << " " << f << "  Is collinear: " << e.check_collinear(f) << std::endl;

    std::cout << "\n\nUtil check_orthogonal()" << std::endl;
    std::cout << e << " " <<  g << "  Is orthogonal: " << e.check_orthogonal(g) << std::endl;

    std::cout << "\n\nUtil negative()" << std::endl;
    std::cout << e << " => "  << -e << std::endl;
}


void comp_test(void)
{
    Vector<int> a({2, 2, 2, 2, 2});
    Vector<int> b({2, 2, 2, 2, 2});

    std::cout << "\n\nOperator ==" << std::endl;
    bool res_equal = a == b;
    std::cout << a << " " << b << " Is equal? Result: "  << res_equal << std::endl;

    std::cout << "\n\nOperator !=" << std::endl;
    bool res_not_equal = a != b;
    std::cout << a << " " << b << " Is NOT equal? Result: "  << res_not_equal << std::endl;
}


int main(void)
{
    // Sum test
    sum_test();

    // Diff test
    diff_test();

    // Mult test
    mult_test();

    // Divided test
    div_test();

    // Vector and scalar mult test
    scalar_vector_mul_test();

    // Index test
    index_test();

    // Utils test
    utils_test();

    // Comparsions test
    comp_test();
}
