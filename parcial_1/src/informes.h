/*
 * informes.c
 *
 *  Created on: 17 oct. 2021
 *      Author: Joa
 */

#ifndef INFORMES_C_
#define INFORMES_C_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"

#include "salon.h"
#include "arcade.h"

//A:

int inf_A_salonConMuchosArcades(Arcades* listArcade, int lenArcade, Salones* listSalon, int lenSalon);

//B:

int inf_B_contarYMostrarArcadesMultiJugador(Arcades* listArcade, int lenArcade, Salones* listSalon , int lenSalon);

//C:

int inf_C_informarSalonCompleto(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade);

//D:

int inf_D_informarArcadesDeUnSalon(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade);

//E:

int inf_E_SalonConMasArcades(Arcades* listArcade, int lenArcade, Salones* listSalon, int lenSalon);

//F:

int inf_F_BilletinGenerado(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade);

//G:

int inf_G_buscarYcontarJuegos (Arcades* list, int len);

//H:

int inf_H_SalonFull(Arcades *listArcade, int lenArcade, Salones *listSalon, int lenSalones);

//I:

int inf_I_promedioArcadePorSalon(Salones* listSalon, int lenSalon, Arcades* listArcade, int lenArcade);


#endif /* INFORMES_C_ */






