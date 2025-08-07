
 template<typename T, typename V>
 std::ostream& operator << (std::ostream& os, const std::pair<T, V> p) {
     os << "[" << p.first << ": " << p.second << "]";
     return os;
 }

 template<typename T, template<class, class...> class C, class... Args>
 std::ostream& operator << (std::ostream& os, const C<T, Args...>& obj) {
    os << "{ ";
    for (auto const val : obj)
        os << val << " ";
    os << "}\n";
    return os;
 }

 void db_out() {
     std::cerr << "\b\b)\n";
 }
 template<typename Head, typename... Tail>
 void db_out(Head H, Tail... T) {
     std::cerr << H << ", ";
     db_out(T...);
 }
 #define db(...) std::cerr << "(" << #__VA_ARGS__  << ") : (", db_out(__VA_ARGS__);
 void db_out_2() {
     std::cerr << "\b\b)\n";
 }
 template<typename Head, typename... Tail>
 void db_out_2(Head H, Tail... T) {
     std::cerr << H << ", ";
     db_out_2(T...);
 }
 #define db2(...) std::cerr << "(" << #__VA_ARGS__  << ") : (", db_out_2(__VA_ARGS__);

 std::ostream& operator<<(std::ostream& out, std::string sss) {
   for (char c : sss)
     out << c;
   return out;
 }
