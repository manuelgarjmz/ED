#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>                          
#include <string>
#include <stdlib.h>
#include <fstream>
#include<CommCtrl.h>             

#include "resource.h"
#include <iostream>

using namespace std;          

HINSTANCE GlobalhInstance;

HWND hAP, hAM, hNOM, hCURP, hRFC, hDATIP, hCALLE, hCOL, hCIU, hEST, hESC, hTEL, hS, hGO, hPR;
HWND hTIPO, hMAR, hPRE, hNDOS, hCVAC, hDESC;
HWND hUS, hCON;
HWND hRUS, hRCON,hRCON2, hRNOM,hRAP,hRAM;
wchar_t AP[100], AMA[100], NOM[100], CURP[100], RFC[100], DATIP[100], CALLE[100], COL[100], CIU[100], EST[100], ESC[100], TEL[100], S[100], GO[100], PR[100];
wchar_t TIPO[100], MAR[100], PRE[100], NDOS[100], CVAC[100], DESC[100];
wchar_t US[100], CON[100];
wchar_t RUS[100],RCON[100],RCON2[100],RNOM[100], RAP[100], RAM[100];

INT_PTR CALLBACK fRV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fRP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK fInicioS(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK fREG(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void fEscribirP();
void fLeerP();
void fLeerU();
void fEscribirU();
void fEscribirV();
void leerArchivo();
bool fComprobarS(string comprobar);
bool fComprobarD(string prueba);
void hMenu(HWND hwnd, WPARAM wparam);
                                             
string fCharToS(wchar_t* wch) {
    wstring ws = wstring(wch);
    string str(ws.begin(), ws.end());
    return str;
}

wchar_t* fStoW(string s) {
    wstring ws = wstring(s.begin(), s.end());
    wchar_t* wcdynamic = new wchar_t[s.length()];
    int i = 0;
    for (; i < s.length(); i++)
    {
        wcdynamic[i] = ws[i];
    }
    wcdynamic[i] = 0;

    return wcdynamic;
}

struct Vacuna {
    string tipo;
    string nombre;
    string dosis;
    string clabev;
    string descripcion;
    string precio;
    void setTipo(string tipo_) {
        tipo = tipo_;
    }
    void setNombre(string nombre_) {
        nombre = nombre_;
    }
    void setDosis(string dosis_) {
        dosis = dosis_;
    }
    void setClave(string clave_) {
        clabev = clave_;
    }
    void setDescripcion(string descripcion_) {
        descripcion = descripcion_;
    }
    void setPrecio(string precio_) {
        precio = precio_;
    }
    static Vacuna* nuevaVacuna(string tipo, string nombre_n, string ndosis_n, string clabev_n, string descripcion_n, string precio_n) {
        Vacuna* nueva = new Vacuna;
        nueva->tipo = tipo;
        nueva->nombre = nombre_n;
        nueva->dosis = ndosis_n;
        nueva->clabev = clabev_n;
        nueva->descripcion = descripcion_n;
        nueva->precio = precio_n;

        return nueva;
    };

};

struct Persona {
    string AP;       //APELLIDO PATERNO
    string AM;        //APELLIDO MATERNO
    string N;          //NOMBRE
    string CURP;
    string RFC;
    string nacimiento;
    string DCA;              //DIRECCION CALLE
    string DCO;             //COLONIA
    string DCI;             //CIUDAD
    string DE;              //ESTADO
    string DEC;             //ESTADO CIVIL
    string tel;
    string DocI;            //DOCUMENTO ID
    string se;                              //SEXO
    string GPO;             //GRUPO OCUPACIONAL
    string PR;              //PERFIL DE RIESGO
    void setAP(string AP_) {
        AP = AP_;
    }
    void setAM(string AM_) {
        AM = AM_;
    }
    void setN(string N_) {
        N = N_;
    }
    void setCURP(string CURP_) {
        CURP = CURP_;
    }
    void setRFC(string RFC_) {
        RFC = RFC_;
    }
    void setNacimiento(string nacimiento_) {
        nacimiento = nacimiento_;
    }
    void setDCA(string DCA_) {
        DCA = DCA_;
    }
    void setDCO(string DCO_) {
        DCO = DCO_;
    }
    void setDCI(string DCI_) {
        DCI = DCI_;
    }
    void setDE(string DE_) {
        DE = DE_;
    }
    void setDEC(string DEC_) {
        DEC = DEC_;
    }
    void setTel(string tel_) {
        tel = tel_;
    }
    void setDocI(string DocI_) {
        DocI_ = DocI_;
    }
    void setSe(string se_) {
        se = se_;
    }
    void setGPO(string GPO_) {
        GPO = GPO_;
    }
    void setPR(string PR_) {
        PR = PR_;
    }
    static Persona* nuevaPersona(string _AP, string _AMA, string _NOM, string _CURP, string fecha,string _RFC, string _CALLE, string _COL, string _CIU, string _EST, string _ESC, string _TEL, string _S, string _GO, string _PR) {
        Persona* Nueva = new Persona;
        Nueva->nacimiento = fecha;
        Nueva->AP = _AP;
        Nueva->AM = _AMA;
        Nueva->N = _NOM;
        Nueva->CURP = _CURP;
        Nueva->RFC = _RFC;
        Nueva->DCA = _CALLE;
        Nueva->DCO = _COL;
        Nueva->DCI = _CIU;
        Nueva->DE = _EST;
        Nueva->DEC = _ESC;
        Nueva->tel = _TEL;
        Nueva->se = _S;
        Nueva->GPO = _GO;
        Nueva->PR = _PR;
        return Nueva;
    }
};

struct Usuario {
    string usuario;
    string contrasena;
    string nombre;
    string ap;
    string am;
    void setUsuario(string _usuario) {
        usuario = _usuario;
    }
    void setConstraseña(string _contrasena) {
        contrasena = _contrasena;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    void setAP(string _ap) {
        ap = _ap;
    }
    void setAM(string _am) {
        am = _am;
    }
    static Usuario* NuevoUsuario(string usuario, string contrasena, string nombre,string ap,string am) {
        Usuario* nuevo = new Usuario;
        nuevo->usuario = usuario;
        nuevo->contrasena = contrasena;
        nuevo->nombre = nombre;
        nuevo->ap = ap;
        nuevo->am = am;
        return nuevo;
    }
};

struct NODOSIMPLE {
    Vacuna* vacuna = NULL;
    NODOSIMPLE* siguiente = NULL;
    NODOSIMPLE* anterior = NULL;
    static NODOSIMPLE* nuevoNodo(Vacuna* dato) {
        NODOSIMPLE* nuevo = new NODOSIMPLE;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->vacuna = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }
};

struct NODOSIMPLEP {
    Persona* person = NULL;
    NODOSIMPLEP* siguiente = NULL;
    NODOSIMPLEP* anterior = NULL;
    static NODOSIMPLEP* nuevoNodo(Persona* dato) {
        NODOSIMPLEP* nuevo = new NODOSIMPLEP;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->person = dato;
        nuevo->anterior = NULL;
        return nuevo;
    }
    
};

struct NODOSIMPLEU {
    Usuario* usuario = NULL;
    NODOSIMPLEU* siguiente = NULL;
    static NODOSIMPLEU* nuevoNodo(Usuario* dato) {
        NODOSIMPLEU* nuevo = new NODOSIMPLEU;
        if (nuevo == NULL) return NULL;
        nuevo->siguiente = NULL;
        nuevo->usuario = dato;
        return nuevo;
    }
};

struct LISTAPERSONA {
    NODOSIMPLEP* ORIGENP = NULL;
    NODOSIMPLEP* FINP = NULL;
    void agregarNodoFinal(Persona* nuevos) {
        if (ORIGENP == NULL) {
            ORIGENP = NODOSIMPLEP::nuevoNodo(nuevos);
            FINP = ORIGENP;
        }
        else {
            FINP->siguiente = NODOSIMPLEP::nuevoNodo(nuevos);
            FINP = FINP->siguiente;
        }
    }
    
}LISTA_P;

struct LISTAVACUNA {
    NODOSIMPLE* ORIGEN = NULL;
    NODOSIMPLE* FIN = NULL;
    void agregarNodoFinal(Vacuna* nuevo) {
        if (ORIGEN == NULL) {
            ORIGEN = NODOSIMPLE::nuevoNodo(nuevo);
            FIN = ORIGEN;
        }
        else {
            FIN->siguiente = NODOSIMPLE::nuevoNodo(nuevo);
            FIN = FIN->siguiente;
        }
    }
}LISTA_S;

struct LISTAUS {
    NODOSIMPLEU* ORIGEN = NULL;
    NODOSIMPLEU* FIN = NULL;
    void agregarNodoFinal(Usuario* nuevo) {
        if (ORIGEN == NULL) {
            ORIGEN = NODOSIMPLEU::nuevoNodo(nuevo);
            FIN = ORIGEN;
        }
        else {
            FIN->siguiente = NODOSIMPLEU::nuevoNodo(nuevo);
            FIN = FIN->siguiente;
        }
    }
}LISTA_U;

void RegistroP(wchar_t AP[100], wchar_t AMA[100], wchar_t NOM[100], wchar_t CURP[100], wchar_t RFC[100], string sfecha, wchar_t CALLE[100], wchar_t COL[100], wchar_t CIU[100], wchar_t EST[100], wchar_t ESC[100], wchar_t TEL[100], wchar_t S[100], wchar_t GO[100], wchar_t PR[100]) {
    string _AP, _AMA, _NOM, _CURP, _RFC, _CALLE, _COL, _CIU, _EST, _ESC, _TEL, _S, _GO, _PR;
    _AP = fCharToS(AP);
    _AMA = fCharToS(AMA);
    _NOM = fCharToS(NOM);
    _CURP = fCharToS(CURP);
    _RFC = fCharToS(RFC);
    _CALLE = fCharToS(CALLE);
    _COL = fCharToS(COL);
    _CIU = fCharToS(CIU);
    _EST = fCharToS(EST);
    _ESC = fCharToS(ESC);
    _TEL = fCharToS(TEL);
    _S = fCharToS(S);
    _GO = fCharToS(GO);
    _PR = fCharToS(PR);
    LISTA_P.agregarNodoFinal(Persona::nuevaPersona(_AP, _AMA, _NOM, _CURP, sfecha, _RFC, _CALLE, _COL, _CIU, _EST, _ESC, _TEL, _S, _GO, _PR));
}
void RegistroV(wchar_t TIPO[100], wchar_t MAR[100], wchar_t PRE[100], wchar_t NDOS[100], wchar_t CVAC[100], wchar_t DESC[100]) {
    string _TIPO, _MAR, _PRE, _NDOS, _CVAC, _DESC;
    _TIPO = fCharToS(TIPO);
    _MAR = fCharToS(MAR);
    _PRE = fCharToS(PRE);
    _NDOS = fCharToS(NDOS);
    _CVAC = fCharToS(CVAC);
    _DESC = fCharToS(DESC);
    LISTA_S.agregarNodoFinal(Vacuna::nuevaVacuna(_TIPO, _MAR, _NDOS, _CVAC, _DESC, _PRE));
}

void CASDialog(HWND hwnd, int iDDialog, DLGPROC callback) {
    HWND hVentana = CreateDialogW(GlobalhInstance, MAKEINTRESOURCE(iDDialog), NULL, callback);
    ShowWindow(hVentana, SW_SHOW);
    DestroyWindow(hwnd);
}

void hMenu(HWND hwnd, WPARAM wparam) {
    switch (LOWORD(wparam)) {
    case ID_REGISTRAR_PERSONA:
        CASDialog(hwnd, IDD_RP, fRP);
        break;
    case ID_REGISTRAR_VACUNA:
        CASDialog(hwnd, IDD_RV, fRV);
        break;
    case ID_SALIR_CERRARSESION:
        CASDialog(hwnd, IDD_IS, fInicioS);
        break;
    case ID_SALIR_SALIR:
        PostQuitMessage(0);
        DestroyWindow(hwnd);
        break;
    }
    
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){

    fLeerP();
    leerArchivo();
    fLeerU();

    GlobalhInstance = hInstance;

    HWND hVentanaInicio = CreateDialogW(hInstance, MAKEINTRESOURCE(IDD_IS), NULL, fInicioS);

    ShowWindow(hVentanaInicio, SW_SHOW);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

INT_PTR CALLBACK fInicioS(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        hUS = GetDlgItem(hwnd, IDC_US);
        hCON = GetDlgItem(hwnd, IDC_CON);
    }
        break;
    case WM_COMMAND :
        switch (LOWORD(wParam)) {
        case IDOK:{
            GetWindowText(hUS, US, 100);
            GetWindowText(hCON, CON, 100);
            string us, con;
            us = fCharToS(US);
            con = fCharToS(CON);
            NODOSIMPLEU* auxiliar;
            auxiliar = LISTA_U.ORIGEN;
            bool salir = false;
            if (auxiliar != NULL) {
                while (salir != true) {

                    if ((auxiliar->usuario->usuario == us) && (auxiliar->usuario->contrasena == con)) {
                        MessageBox(hwnd, L"Inicio sesion correctamente", L"CORRECTO", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_RP, fRP);
                    }
                    else if ((auxiliar->usuario->usuario == us) && (auxiliar->usuario->contrasena != con)) {
                        MessageBox(hwnd, L"Contraseña incorrecta", L"ERROR", MB_ICONEXCLAMATION);
                    }
                    else if (auxiliar->usuario->usuario != us && auxiliar->siguiente == NULL) {
                        MessageBox(hwnd, L"Usuario no encontrado", L"USUARIO NO ENCONTRADO", MB_ICONEXCLAMATION);
                    }
                    if (auxiliar->siguiente == NULL) {
                        salir = true;
                    }
                    else {
                        auxiliar = auxiliar->siguiente;
                    }
                }
            }
            else {
                MessageBox(hwnd, L"No existen usuarios registrados", L"ERROR", MB_ICONEXCLAMATION);
            }
            LISTA_U.ORIGEN;
        }
            break;
        case IDC_REG: {
            CASDialog(hwnd, IDD_REG,fREG);
        }
            break;
        case IDCANCEL: {
            PostQuitMessage(0);
            DestroyWindow(hwnd);
        }
        }
    }
    return false;
}

INT_PTR CALLBACK fRP(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hAP = GetDlgItem(hwnd, IDC_AP);                  
        hAM = GetDlgItem(hwnd, IDC_AM);
        hNOM = GetDlgItem(hwnd, IDC_NOM);        
        hCURP = GetDlgItem(hwnd, IDC_CURP);
        hRFC = GetDlgItem(hwnd, IDC_RFC);
        hDATIP = GetDlgItem(hwnd, IDC_DATETIMEPICKER1);
        hCALLE = GetDlgItem(hwnd, IDC_CALLE);
        hCOL = GetDlgItem(hwnd, IDC_COL);
        hCIU = GetDlgItem(hwnd, IDC_CIU);
        hEST = GetDlgItem(hwnd, IDC_EST);
        hESC = GetDlgItem(hwnd, IDC_ESC);
        hTEL = GetDlgItem(hwnd, IDC_TEL);
        hS = GetDlgItem(hwnd, IDC_S);
        hGO = GetDlgItem(hwnd, IDC_GO);
        hPR = GetDlgItem(hwnd, IDC_PR);
        string es1 = "Soltero(a)";
        string es2 = "Casado(a)";
        string es4 = "Separado(a)";
        string es5 = "Viudo(a)";
        string es6 = "Otro";
        string s1 = "Masculino";
        string s2 = "Femenino";
        string s3 = "Otro";
        wchar_t* solt1 = fStoW(es1);
        wchar_t* solt2 = fStoW(es2);
        wchar_t* solt4 = fStoW(es4);
        wchar_t* solt5 = fStoW(es5);
        wchar_t* solt6 = fStoW(es6);
        wchar_t* sw1 = fStoW(s1);
        wchar_t* sw2 = fStoW(s2);
        wchar_t* sw3 = fStoW(s3);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt1);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt2);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt4);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt5);
        SendMessage(hESC, CB_ADDSTRING, 0, (LPARAM)solt6);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw1);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw2);
        SendMessage(hS, CB_ADDSTRING, 0, (LPARAM)sw3);
    }
        break;
    case WM_COMMAND: {
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDOK: {
            SYSTEMTIME fecha;
            string sfecha;
            GetWindowText(hAP, AP, 100);
            GetWindowText(hAM, AMA, 100);
            GetWindowText(hNOM, NOM, 100);
            GetWindowText(hCURP, CURP, 100);
            GetWindowText(hRFC, RFC, 100);
            DateTime_GetSystemtime(hDATIP, &fecha);                          
            GetWindowText(hCALLE, CALLE, 100);
            GetWindowText(hCOL, COL, 100);
            GetWindowText(hCIU, CIU, 100);
            GetWindowText(hEST, EST, 100);
            GetWindowText(hESC, ESC, 100);            
            GetWindowText(hTEL, TEL, 100);
            GetWindowText(hS, S, 100);                 
            GetWindowText(hGO, GO, 100);
            GetWindowText(hPR, PR, 100);
            sfecha = to_string(fecha.wDay);
            sfecha.append("/");
            sfecha.append(to_string(fecha.wMonth));
            sfecha.append("/");
            sfecha.append(to_string(fecha.wYear));
            if ((AP[0] != 0) && (AMA[0] != 0) && (NOM[0] != 0) && (CURP[0] != 0) && (RFC[0] != 0) && (CALLE[0] != 0) && (COL[0] != 0) && (CIU[0] != 0) && (EST[0] != 0) && (ESC[0] != 0) && (TEL[0] != 0) && (S[0] != 0) && (GO[0] != 0) && (PR[0] != 0)) {
                string CURPC;
                CURPC = fCharToS(CURP);
                if (fComprobarS(CURPC) == true){
                    if (LISTA_P.ORIGENP != NULL) {
                        NODOSIMPLEP* auxiliar;
                        auxiliar = LISTA_P.ORIGENP;
                        bool salir = false;
                        while (salir != true) {
                            if (auxiliar->person->CURP == CURPC) {
                                MessageBox(hwnd, L"El CURP ya esta registrado en el sistema", L"Error en registro", MB_ICONINFORMATION);
                                salir = true;
                            }
                            else if (auxiliar->siguiente == NULL) {
                                salir = true;
                            }
                            else {
                                auxiliar = auxiliar->siguiente;
                            }
                        }
                        if (auxiliar->siguiente == NULL && auxiliar->person->CURP != CURPC) {
                            RegistroP(AP, AMA, NOM, CURP, RFC, sfecha, CALLE, COL, CIU, EST, ESC, TEL, S, GO, PR);
                            fEscribirP();
                            MessageBox(hwnd, L"Persona registrada correctamente", L"Registro de persona exitoso", MB_ICONINFORMATION);
                            CASDialog(hwnd, IDD_RP, fRP);
                        }
                    }
                    else {
                        RegistroP(AP, AMA, NOM, CURP, RFC, sfecha, CALLE, COL, CIU, EST, ESC, TEL, S, GO, PR);
                        fEscribirP();
                        MessageBox(hwnd, L"Persona registrada correctamente", L"Registro de persona exitoso", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_RP, fRP);
                    }
            }
                else {
                    MessageBox(hwnd, L"No se aceptan espacios en el CURP", L"CURP CON ESPACIOS", MB_ICONINFORMATION);
                }
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"FALTA INFORMACION", MB_ICONINFORMATION);
            }
        }
            break;
        case IDCANCEL:

            break;
        }
    }
        break;
    }
    
    return false;
}

INT_PTR CALLBACK fRV(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_INITDIALOG: {
        HMENU hMenuP = LoadMenu(GlobalhInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenuP);
        hTIPO = GetDlgItem(hwnd, IDC_TIPO);  
        hMAR = GetDlgItem(hwnd, IDC_MAR);
        hPRE = GetDlgItem(hwnd, IDC_PRE);
        hNDOS = GetDlgItem(hwnd, IDC_NDOS);
        hCVAC= GetDlgItem(hwnd, IDC_CVAC);
        hDESC = GetDlgItem(hwnd, IDC_DESC);
    }
                      break;
    case WM_COMMAND: {
        hMenu(hwnd, wparam);
        switch (LOWORD(wparam)) {
        case IDC_ACEPTAR:
        
            GetWindowText(hTIPO, TIPO, 100);
            GetWindowText(hMAR, MAR, 100);
            GetWindowText(hPRE, PRE, 100);
            GetWindowText(hNDOS, NDOS, 100);
            GetWindowText(hCVAC, CVAC, 100);
            GetWindowText(hDESC, DESC, 100);
            if ((TIPO[0] != 0) && (MAR[0] != 0) && (PRE[0] != 0) && (NDOS[0] != 0) && (CVAC[0] != 0) && (DESC[0] != 0)) {
                string comprobar=fCharToS(PRE);
                string comprobarcv = fCharToS(CVAC);
                if (fComprobarD(comprobar) == true) {
                    if (LISTA_S.ORIGEN != NULL) {
                    NODOSIMPLE* auxiliar;
                    auxiliar = LISTA_S.ORIGEN;
                    bool salir = false;
                    while (salir != true) {
                        if (auxiliar->vacuna->clabev == comprobarcv) {
                            MessageBox(hwnd, L"La clave de vacuna ya esta registrada en el sistema", L"Clave no valida", MB_ICONINFORMATION);
                            salir = true;
                        }
                        else if (auxiliar->siguiente == NULL) {
                            salir = true;
                        }
                        else {
                            auxiliar = auxiliar->siguiente;
                        }

                    }
                    if (auxiliar->siguiente == NULL && auxiliar->vacuna->clabev != comprobarcv) {
                        RegistroV(TIPO, MAR, PRE, NDOS, CVAC, DESC);
                        fEscribirV();
                        MessageBox(hwnd, L"VACUNA REGISTRADA CON EXITO", L"REGISTRO CORRECTO", MB_ICONEXCLAMATION);
                        CASDialog(hwnd, IDD_RV, fRV);
                    }
                    }
                    else {
                        RegistroV(TIPO, MAR, PRE, NDOS, CVAC, DESC);
                        fEscribirV();
                        MessageBox(hwnd, L"VACUNA REGISTRADA CON EXITO", L"REGISTRO CORRECTO", MB_ICONEXCLAMATION);
                        CASDialog(hwnd, IDD_RV, fRV);
                    }
                }
                else {
                    MessageBox(hwnd, L"EL PRECIO SOLO ACEPTA NUMEROS ENTEROS Y DECIMALES",L"ERROR EN PRECIO",MB_ICONINFORMATION);
                }
            }
            else {
                MessageBox(hwnd, L"Por favor llene todos los datos", L"Datos faltantes",MB_ICONINFORMATION);
            }
        
        break;
        }
        
        
    }
                   break;

    }
    return false;
}

INT_PTR CALLBACK fREG(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG:
        hRUS = GetDlgItem(hwnd,IDC_US);
        hRCON = GetDlgItem(hwnd, IDC_PASS1);
        hRCON2 = GetDlgItem(hwnd, IDC_PASS2);
        hRNOM = GetDlgItem(hwnd, IDC_RNOM);
        hRAP = GetDlgItem(hwnd, IDC_RAP);
        hRAM = GetDlgItem(hwnd, IDC_RAM);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK: {
            GetWindowText(hRUS, RUS, 100);
            GetWindowText(hRCON, RCON, 100);
            GetWindowText(hRCON2,RCON2,100);
            GetWindowText(hRNOM, RNOM, 100);
            GetWindowText(hRAP, RAP, 100);
            GetWindowText(hRAM, RAM, 100);
            string rus, rcon,rcon2,rnom,rap,ram;
            rus = fCharToS(RUS);
            rcon = fCharToS(RCON);
            rcon2 = fCharToS(RCON2);
            rnom = fCharToS(RNOM);
            rap = fCharToS(RAP);
            ram = fCharToS(RAM);
            NODOSIMPLEU* auxiliar;
            auxiliar = LISTA_U.ORIGEN;
            if (auxiliar != NULL) {
                bool salir = false;
                while (salir != true) {
                    if ((auxiliar->usuario->usuario) == rus) {
                        MessageBox(hwnd, L"El nombre de usuario ya esta registradp", L"Usuario ya registrado", MB_ICONINFORMATION);
                        salir = true;
                        exit;
                    }
                    if (auxiliar->siguiente == NULL) {
                        salir = true;
                    }
                    else {
                        auxiliar = auxiliar->siguiente;
                    }
                }
                if ((auxiliar->siguiente == NULL) && (auxiliar->usuario->usuario != rus) && (rcon2 == rcon)) {
                    if (fComprobarS(rus) == false) {
                        MessageBox(hwnd, L"El nombre de usuario no debe tener espacios", L"Espacios", MB_ICONINFORMATION);
                        exit;
                    }
                    else if ((rnom.length() == 0) || (rap.length() == 0) || (ram.length() == 0)) {
                        MessageBox(hwnd, L"Llene todos los datos del usuario", L"Faltan datos", MB_ICONINFORMATION);
                        exit;
                    }
                    else {
                        LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(rus, rcon, rnom, rap, ram));
                        fEscribirU();
                        MessageBox(hwnd, L"Usuario registrado con exito", L"Registro exitoso", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_IS, fInicioS);
                    }
                }
                else if((auxiliar->siguiente == NULL) && (auxiliar->usuario->usuario!=rus)&&(rcon!=rcon2)){
                    MessageBox(hwnd,L"Las contraseñas no coinciden, ingreselas de nuevo",L"Contraseñas no coinciden",MB_ICONINFORMATION);
                }
            }
            else {
                if (rcon2 == rcon) {
                    if (fComprobarS(rus) == false) {
                        MessageBox(hwnd, L"La clave de usuario no debe contener espacio", L"Clave con espacio", MB_ICONINFORMATION);
                        exit;
                    }
                    else if ((rnom.length()==0)||(rap.length()==0)||(ram.length()==0)) {
                        MessageBox(hwnd, L"Llene todos los datos del usuario", L"Faltan datos", MB_ICONINFORMATION);
                        exit;
                    }
                    else {
                        LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(rus, rcon, rnom, rap, ram));
                        fEscribirU();
                        MessageBox(hwnd, L"Usuario registrado con exito", L"Registro exitoso", MB_ICONINFORMATION);
                        CASDialog(hwnd, IDD_IS, fInicioS);
                    }
                }
                else if (rcon != rcon2) {
                    MessageBox(hwnd, L"Las contraseñas no coinciden, ingreselas de nuevo", L"Contraseñas no coinciden", MB_ICONINFORMATION);
                }
            }
        }
            break;
        case IDCANCEL: {
            CASDialog(hwnd, IDD_IS, fInicioS);
        }
            break;
        }
        break;
    }
    return false;
}

void fEscribirP() {
    NODOSIMPLEP* auxiliar;
    auxiliar= LISTA_P.ORIGENP;
    bool salir=false;
    ofstream archivop("Personas.txt");
    if (archivop.is_open()) {
        if (auxiliar!=NULL) {
            while (salir != true) {
                archivop << auxiliar->person->AP;
                archivop << ",";
                archivop << auxiliar->person->AM;
                archivop << ",";
                archivop << auxiliar->person->N;
                archivop << ",";
                archivop << auxiliar->person->CURP;
                archivop << ",";
                archivop << auxiliar->person->nacimiento;
                archivop << ",";
                archivop << auxiliar->person->RFC;
                archivop << ",";
                archivop << auxiliar->person->DCA;
                archivop << ",";
                archivop << auxiliar->person->DCO;
                archivop << ",";
                archivop << auxiliar->person->DCI;
                archivop << ",";
                archivop << auxiliar->person->DE;
                archivop << ",";
                archivop << auxiliar->person->DEC;
                archivop << ",";
                archivop << auxiliar->person->tel;
                archivop << ",";
                archivop << auxiliar->person->se;
                archivop << ",";
                archivop << auxiliar->person->GPO;
                archivop << ",";
                archivop << auxiliar->person->PR;
                archivop << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivop.close();
}

void fEscribirV() {
    NODOSIMPLE* auxiliar;
    auxiliar = LISTA_S.ORIGEN;
    bool salir = false;
    ofstream archivov("Vacunas.txt");
    if (archivov.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivov << auxiliar->vacuna->tipo;
                archivov << ",";
                archivov << auxiliar->vacuna->nombre;
                archivov << ",";
                archivov << auxiliar->vacuna->dosis;
                archivov << ",";
                archivov << auxiliar->vacuna->clabev;
                archivov << ",";
                archivov << auxiliar->vacuna->descripcion;
                archivov << ",";
                archivov << auxiliar->vacuna->precio;
                archivov << ","<<endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivov.close();
}

void fEscribirU() {
    NODOSIMPLEU* auxiliar;
    auxiliar = LISTA_U.ORIGEN;
    bool salir = false;
    ofstream archivou("Usuario.txt");
    if (archivou.is_open()) {
        if (auxiliar != NULL) {
            while (salir != true) {
                archivou << auxiliar->usuario->usuario;
                archivou << ",";
                archivou << auxiliar->usuario->contrasena;
                archivou << ",";
                archivou << auxiliar->usuario->nombre;
                archivou << ",";
                archivou << auxiliar->usuario->ap;
                archivou << ",";
                archivou << auxiliar->usuario->am;
                archivou << "," << endl;
                if (auxiliar->siguiente == NULL) {
                    salir = true;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
        }
    }
    archivou.close();
}

void fLeerP() {   
    ifstream archivo("Personas.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Persona* nueva = new Persona;
            string lineap;
            getline(archivo, lineap);
            if ((lineap.length())!=0) {
                nueva->setAP(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setAM(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setN(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setCURP(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setNacimiento(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setRFC(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCA(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCO(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDCI(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDE(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setDEC(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setTel(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setSe(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setGPO(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                nueva->setPR(lineap.substr(0, lineap.find(",")));
                lineap = lineap.substr(lineap.find(",") + 1);
                LISTA_P.agregarNodoFinal(Persona::nuevaPersona(nueva->AP, nueva->AM, nueva->N, nueva->CURP, nueva->nacimiento, nueva->RFC, nueva->DCA, nueva->DCO, nueva->DCI, nueva->DE, nueva->DEC, nueva->tel, nueva->se, nueva->GPO, nueva->PR));
            }
            delete nueva;
        }
    }
    archivo.close();
}

void leerArchivo() {
    ifstream archivo("Vacunas.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Vacuna* nueva = new Vacuna;
            string linea;
            getline(archivo, linea);
            if ((linea.length()) != 0) {
                nueva->setTipo(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setNombre(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setDosis(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setClave(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setDescripcion(linea.substr(0, linea.find(",")));
                linea = linea.substr(linea.find(",") + 1);
                nueva->setPrecio(linea.substr(0, linea.find(",")));
                LISTA_S.agregarNodoFinal(Vacuna::nuevaVacuna(nueva->tipo, nueva->nombre, nueva->dosis, nueva->clabev, nueva->descripcion, nueva->precio));
            }
            delete nueva;
        }
    }
    archivo.close();
}

void fLeerU() {
    ifstream archivo("Usuario.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Usuario* nuevo = new Usuario;
            string linea;
            getline(archivo, linea); {
                if ((linea.length()) != 0) {
                    nuevo->setUsuario(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setConstraseña(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setNombre(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setAP(linea.substr(0, linea.find(",")));
                    linea = linea.substr(linea.find(",") + 1);
                    nuevo->setAM(linea.substr(0, linea.find(",")));
                    LISTA_U.agregarNodoFinal(Usuario::NuevoUsuario(nuevo->usuario, nuevo->contrasena,nuevo->nombre,nuevo->ap,nuevo->am));
                }
                delete nuevo;
            }
        }
    }
    archivo.close();
}

bool fComprobarS(string comprobar) {
    for (int i = 0; i < comprobar.length(); i++) {
        if (isspace(comprobar[i])){
            return false;                          
        }
    }
    return true;                                   
}

bool fComprobarD(string prueba) {
    string punto = ".";
    for (int i = 0; i < prueba.length(); i++) {
        if (!isdigit(prueba[i]) && prueba[i] != punto[0]) {
            return false;
        }
    }
    return true;
}