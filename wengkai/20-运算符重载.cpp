class Fi{
public:
  Fi(){}
};

class Fee {
public:
  Fee(int) {}
  Fee(const Fi&){} 
};

int main(){
  Fee fee = 1;
  Fi fi;
  Fee fum = fi;
  fum = fi;
}