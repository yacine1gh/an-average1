
#include <stdio.h>

typedef struct Module {
  char nom[50];
  float td;
  float tp;
  float quiz;
  float exam;
  float moyenne;
} Module;

float calculerMoyenneModule(Module module) {
  return (module.td + module.tp + module.quiz + module.exam) / 4;
}
void afficherModule(Module module) {
  printf("Module name: %s\n", module.nom);
  printf("grade td: %.2f\n", module.td);
  printf("grade tp: %.2f\n", module.tp);
  printf("grade quiz: %.2f\n", module.quiz);
  printf("grade exam: %.2f\n", module.exam);
  printf("an average: %.2f\n", module.moyenne);
} 
int estEchoueModule(Module module) {
  return module.moyenne < 10;
}
float calculerMoyenneGenerale(Module modules[], int nbModules) {
  float sommeMoyennes = 0;
  for (int i = 0; i < nbModules; i++) {
    sommeMoyennes += modules[i].moyenne;
  }
  return sommeMoyennes / nbModules;
}
void afficherModules(Module modules[], int nbModules) {
  for (int i = 0; i < nbModules; i++) {
    afficherModule(modules[i]);
  }
}
int main() {
  Module modules[7];
  const char* nomsModules[] = {
    "Algorithmique",
    "Analyse",
    "Système d'exploitation",
    "Logique mathématique",
    "Probabilité",
    "Algèbre",
    "Anglsh"
  };
  for (int i = 0; i < 7; i++) {
    strcpy(modules[i].nom, nomsModules[i]);
    printf("Enter the material information %d (%s):\n", i + 1, modules[i].nom);
    printf("grade td: ");
    scanf("%f", &modules[i].td);
    printf("grade tp: ");
    scanf("%f", &modules[i].tp);
    printf("grade quiz: ");
    scanf("%f", &modules[i].quiz);
    printf("grade exam: ");
    scanf("%f", &modules[i].exam);
    modules[i].moyenne = calculerMoyenneModule(modules[i]);
  }
  afficherModules(modules, 7);
  float moyenneGenerale = calculerMoyenneGenerale(modules, 7);
  printf("Overall average: %.2f\n", moyenneGenerale);
  int nbModulesEchoues = 0;
  for (int i = 0; i < 7; i++) {
    if (estEchoueModule(modules[i])) {
      nbModulesEchoues++;
    }
  }
  if (nbModulesEchoues > 0) {
    printf("A failing student %d .\n", nbModulesEchoues);
  } else {
    printf("The student is successful in all subjects.\n");
  }
  return 0;
}