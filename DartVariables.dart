void main() {
  var name = "Emran"; //Type inferred as String
  final age = 25; // Final Variable (immutable)
  const pi = 3.14; // Constant variable (immutable)
  int scoure = 95;
  double temp = 23.5;
  bool isDartFun = true;
  String greeting = "Hello Dart";
  List<int> number = [1, 2, 3];
  Map<String, int> scoures = {'Ali': 95, 'babu': 83};

  //Dynamic Type:

  dynamic dynamicVariable = 42;
  dynamicVariable = "Hello";

  //Null Safety:

  String? nullableVariable = null;
}
