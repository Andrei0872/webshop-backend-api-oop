class OrderService {
  private:
    ProductService productService;
    UserService userService;

  public:
    OrderService(const ProductService &ps, const UserService &us):
      productService(ps), userService(us) {};

    void insertProduct (int userId, int productId, int q) {
      cout << userService.getAll().size();
    }
};