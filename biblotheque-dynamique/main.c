#include <dlfcn.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/**
 * test du chargement de la bibliothèque dynamique
 * renvoie NULL si erreur
 */
void test_chargement_biblio(){
    void *bibliotheque;
    
    bibliotheque=dlopen("./biblio.so",RTLD_NOW);
    CU_ASSERT_PTR_NOT_NULL(bibliotheque);
    
    dlclose(bibliotheque);
}

/**
 * test du chargement de la fonction 'toto' de la bibliothèque dynamique
 * renvoie NULL si erreur pointeur de fonction sinon
 */
void test_fonction_toto_biblio(){
    void *bibliotheque;
    int (*fonction_toto)(int);

    bibliotheque=dlopen("./biblio.so",RTLD_NOW);
    CU_ASSERT_PTR_NOT_NULL(bibliotheque);

    fonction_toto=dlsym(bibliotheque,"toto");
    CU_ASSERT_PTR_NOT_NULL(fonction_toto);
    CU_ASSERT_EQUAL(fonction_toto(5),6);
    
    dlclose(bibliotheque);
}

/**
 * La fonction 'tutu' n'existe pas ,donc renvoie NULL
 */
void test_fonction_tutu_biblio(){
    void *bibliotheque;
    int (*fonction_tutu)(int);

    bibliotheque=dlopen("./biblio.so",RTLD_NOW);
    CU_ASSERT_PTR_NOT_NULL(bibliotheque);

    fonction_tutu=dlsym(bibliotheque,"tutu");
    CU_ASSERT_PTR_NULL(fonction_tutu);
    
    dlclose(bibliotheque);
}

/**
 * Lancement des tests unitaires
 */
int main(){
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("test bliotheque dynamique",0,0);
    
    CU_add_test(suite, "test_chargement_biblio", test_chargement_biblio);
    CU_add_test(suite, "test_fonction_toto", test_fonction_toto_biblio);
    CU_add_test(suite, "test_fonction_tutu", test_fonction_tutu_biblio);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
