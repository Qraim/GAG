//
// Created by qraim on 07/04/23.
//

#include "gag.h"


gag::gag(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Top section
    QGridLayout *topLayout = new QGridLayout;
    topLayout->setSpacing(10);
    topLayout->setAlignment(Qt::AlignCenter);

    // Ajout des champs d'entrée et des étiquettes au QGridLayout fixeInputsLayout
    Materiau = new QComboBox(this);
    Materiau->setFixedSize(75, 25);
    Materiau->addItem("PVC");
    Materiau->addItem("PN");
    Materiau->addItem("Fonte");
    Materiau->addItem("Alu");

    topLayout->addWidget(Materiau);

    // Create QLineEdit pointers and corresponding labels for the top section
    Debit = new QLineEdit;
    Espacement = new QLineEdit;
    Diametre = new QLineEdit;
    Longueur = new QLineEdit;
    Hauteur = new QLineEdit;

    // Create a custom locale with a period as the decimal separator
// Create a custom locale with a period as the decimal separator
    QLocale customLocale = QLocale::French;

// Add input validators to QLineEdit widgets with the custom locale
    QDoubleValidator *debitValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 2, this);
    debitValidator->setLocale(customLocale);
    Debit->setValidator(debitValidator);

    QDoubleValidator *espacementValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 2, this);
    espacementValidator->setLocale(customLocale);
    Espacement->setValidator(espacementValidator);

    QDoubleValidator *diametreValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 2, this);
    diametreValidator->setLocale(customLocale);
    Diametre->setValidator(diametreValidator);

    QDoubleValidator *longueurValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 2, this);
    longueurValidator->setLocale(customLocale);
    Longueur->setValidator(longueurValidator);

    QDoubleValidator *hauteurValidator = new QDoubleValidator(0, std::numeric_limits<double>::max(), 2, this);
    hauteurValidator->setLocale(customLocale);
    Hauteur->setValidator(hauteurValidator);


    QLabel *labelDebit = new QLabel("Debit: l/h");
    QLabel *labelEspacement = new QLabel("Espacement: m ");
    QLabel *labelDiametre = new QLabel("Diametre: mm");
    QLabel *labelLongueur = new QLabel("Longueur: m");
    QLabel *labelHauteur = new QLabel("Hauteur: m");

    // Add labels and QLineEdit widgets to the topLayout
    topLayout->addWidget(labelDebit, 1, 0, Qt::AlignCenter);
    topLayout->addWidget(Debit, 2, 0, Qt::AlignCenter);
    topLayout->addWidget(labelEspacement, 1, 1, Qt::AlignCenter);
    topLayout->addWidget(Espacement, 2, 1, Qt::AlignCenter);
    topLayout->addWidget(labelDiametre, 1, 2, Qt::AlignCenter);
    topLayout->addWidget(Diametre, 2, 2, Qt::AlignCenter);
    topLayout->addWidget(labelLongueur, 1, 3, Qt::AlignCenter);
    topLayout->addWidget(Longueur, 2, 3, Qt::AlignCenter);
    topLayout->addWidget(labelHauteur, 1, 4, Qt::AlignCenter);
    topLayout->addWidget(Hauteur, 2, 4, Qt::AlignCenter);

    // Add additional labels under the QLineEdit widgets
    QLabel *labelNumero = new QLabel("Numéro");
    QLabel *labelDebit2 = new QLabel("Debit");
    QLabel *labelEspacement2 = new QLabel("Espacement");
    QLabel *labelDiametre2 = new QLabel("Diametre");
    QLabel *labelLongueur2 = new QLabel("Longueur");
    QLabel *labelHauteur2 = new QLabel("Hauteur");
    QLabel *labelPerte = new QLabel("Perte");
    QLabel *labelPiezo = new QLabel("Piezo");
    QLabel *labelSigmaPerte = new QLabel("ΣPerte");
    QLabel *labelSigmaPiezo = new QLabel("ΣPiezo");

    topLayout->addWidget(labelNumero, 3, 0, Qt::AlignRight);
    topLayout->addWidget(labelDebit2, 3, 1, Qt::AlignRight);
    topLayout->addWidget(labelEspacement2, 3, 2, Qt::AlignRight);
    topLayout->addWidget(labelDiametre2, 3, 3, Qt::AlignRight);
    topLayout->addWidget(labelLongueur2, 3, 4, Qt::AlignRight);
    topLayout->addWidget(labelHauteur2, 3, 5, Qt::AlignRight);
    topLayout->addWidget(labelPerte, 3, 6, Qt::AlignCenter);
    topLayout->addWidget(labelPiezo, 3, 7, Qt::AlignCenter);
    topLayout->addWidget(labelSigmaPerte, 3, 8, Qt::AlignCenter);
    topLayout->addWidget(labelSigmaPiezo, 3, 9, Qt::AlignCenter);

    for (int col = 0; col < 10; ++col) {
        topLayout->setColumnStretch(col, 1);
    }

    mainLayout->addLayout(topLayout);


    // Mid section
    QScrollArea *scrollArea = new QScrollArea;
    mainLayout->addWidget(scrollArea);

    QWidget *scrollAreaContents = new QWidget;
    scrollAreaLayout = new QGridLayout(scrollAreaContents);
    scrollArea->setWidget(scrollAreaContents);
    scrollArea->setWidgetResizable(true);

    // Bottom section
    QGridLayout *bottomLayout = new QGridLayout;
    bottomLayout->setSpacing(10);
    bottomLayout->setAlignment(Qt::AlignCenter);

    // Create QLineEdit pointers and corresponding labels for the bottom section
    CumulLongueur = new QLineEdit;
    Cumulhauteur = new QLineEdit;
    CumulPerte = new QLineEdit;
    CumulPiezo = new QLineEdit;

    QLabel *labelCumulLongueur = new QLabel("Cumul Longueur:");
    QLabel *labelCumulhauteur = new QLabel("Cumul Hauteur:");
    QLabel *labelCumulPerte = new QLabel("Cumul Perte:");
    QLabel *labelCumulPiezo = new QLabel("Cumul Piezo:");

    // Add labels and QLineEdit widgets to the bottomLayout
    bottomLayout->addWidget(labelCumulLongueur, 0, 0, Qt::AlignCenter);
    bottomLayout->addWidget(CumulLongueur, 0, 1, Qt::AlignCenter);
    bottomLayout->addWidget(labelCumulhauteur, 1, 0, Qt::AlignCenter);
    bottomLayout->addWidget(Cumulhauteur, 1, 1, Qt::AlignCenter);
    bottomLayout->addWidget(labelCumulPerte, 2, 0, Qt::AlignCenter);
    bottomLayout->addWidget(CumulPerte, 2, 1, Qt::AlignCenter);
    bottomLayout->addWidget(labelCumulPiezo, 3, 0, Qt::AlignCenter);
    bottomLayout->addWidget(CumulPiezo, 3, 1, Qt::AlignCenter);

    connect(Debit, &QLineEdit::returnPressed, this, &gag::AjoutDonnee);
    connect(Espacement, &QLineEdit::returnPressed, this, &gag::AjoutDonnee);
    connect(Diametre, &QLineEdit::returnPressed, this, &gag::AjoutDonnee);
    connect(Longueur, &QLineEdit::returnPressed, this, &gag::AjoutDonnee);
    connect(Hauteur, &QLineEdit::returnPressed, this, &gag::AjoutDonnee);

    mainLayout->addLayout(bottomLayout);

    this->setLayout(mainLayout);

    Debit->setFocus();
}

void gag::AjoutDonnee() {
    if (!Debit->text().isEmpty() && !Espacement->text().isEmpty() &&
        !Diametre->text().isEmpty() && !Longueur->text().isEmpty() &&
        !Hauteur->text().isEmpty()) {

        std::vector<float> temp;
        temp.resize(10);

        float numero = _Donnees.size()+1;

        QString debitText = Debit->text();
        debitText.replace(',', '.');
        float debit = debitText.toFloat();

        QString espacementText = Espacement->text();
        espacementText.replace(',', '.');
        float espacement = espacementText.toFloat();

        QString diametreText = Diametre->text();
        diametreText.replace(',', '.');
        float diametre = diametreText.toFloat();

        QString longueurText = Longueur->text();
        longueurText.replace(',', '.');
        float longueur = longueurText.toFloat();

        QString hauteurText = Hauteur->text();
        hauteurText.replace(',', '.');
        float hauteur = hauteurText.toFloat();


        temp[0] = numero;
        temp[1] = debit;
        temp[2] = espacement;
        temp[3] = diametre;
        temp[4] = longueur;
        temp[5] = hauteur;

        _Donnees.push_back(temp);

        AjoutLigne();

    } else {
        focusNextInput();
    }
}

void gag::AjoutLigne(){
    // Add a new line in the scroll area with the values
    // Add a new line in the scroll area with the values
    int row = _Donnees.size() - 1;
    std::vector<float> temp = _Donnees[row];
    for (int col = 0; col < temp.size(); ++col) {
        QLineEdit *valueLabel = new QLineEdit(QString::number(temp[col]));
        valueLabel->setReadOnly(true);
        valueLabel->setAlignment(Qt::AlignCenter);
        valueLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        valueLabel->setFixedHeight(40); // Fixe la taille de la ligne.
        // Adjust the row number to add the QLineEdit widget
        // at the top and below the previous one.
        scrollAreaLayout->addWidget(valueLabel, row, col, Qt::AlignTop);
    }

    // On fixe l'espacement vertical et l'alignement.
    scrollAreaLayout->setVerticalSpacing(15);
    scrollAreaLayout->setAlignment(Qt::AlignTop);

    Debit->setFocus();

}

// La fonction "focusPreviousInput" est appelée lorsqu'un raccourci clavier est utilisé pour passer au champ d'entrée précédent.
void gag::focusPreviousInput() {
    // Si l'entrée "hauteur" a le focus, passe le focus à l'entrée "longueur".
    if (Hauteur->hasFocus()) {
        Longueur->setFocus();
        return;
    }
        // Si l'entrée "longueur" a le focus, passe le focus à l'entrée "diametre".
    else if (Longueur->hasFocus()) {
        Diametre->setFocus();
        return;
    }
        // Si l'entrée "diametre" a le focus, passe le focus à l'entrée "debit".
    else if (Diametre->hasFocus()){
        Espacement->setFocus();
        return;
    }

    else if (Espacement->hasFocus()){
        Debit->setFocus();
    }
}


// La fonction "focusNextInput" est appelée lorsqu'un raccourci clavier est utilisé pour passer au champ d'entrée suivant.
void gag::focusNextInput() {

    // Si l'entrée "hauteur" a le focus, passe le focus à l'entrée "longueur".
    if (Debit->hasFocus()) {
        Espacement->setFocus();
        return;
    }
        // Si l'entrée "longueur" a le focus, passe le focus à l'entrée "diametre".
    else if (Espacement->hasFocus()) {
        Diametre->setFocus();
        return;
    }
        // Si l'entrée "diametre" a le focus, passe le focus à l'entrée "debit".
    else if (Diametre->hasFocus()){
        Longueur->setFocus();
        return;
    }

    else if (Longueur->hasFocus()){
        Hauteur->setFocus();
    }
}


void gag::calcul() {
    // Initialise les paramètres.
    float k = 0;
    float a = 0;
    float b = 0;

    // Initialise les variables.
    float debit = 0;
    float debitM3 = 0; // Débit en m3/h
    float debitLs = 0; // Débit en l/s
    float espacement = 0;
    float diametre = 0;
    float longueur = 0;
    float hauteur = 0;
    float perteCharge = 0;
    float piezo = 0;
    float sigmaDebit = 0; // Cumul débit
    float vitesse = 0;
    float aireTuyau = 0;
    float sigmaPiezo = 0; // Cumul piezo
    float sigmaPerte = 0; // Cumul perte
    float sigmaLongueur = 0;
    float sigmaHauteur = 0;

    // Sélectionne les critères en fonction de la matière.
    if (Materiau->currentText() == "PVC" || Materiau->currentText() == "PN") {
        k = 831743.11;
        a = 1.75;
        b = -4.75;
    } else if (Materiau->currentText() == "Fonte") {
        k = 1458844.82;
        a = 1.83;
        b = -4.89;
    } else if (Materiau->currentText() == "Alu") {
        k = 1707785.38;
        a = 1.89;
        b = -4.87;
    }

    // Effectue les calculs pour chaque ligne de données.
    for (int i = 0; i < _Donnees.size(); ++i) {

        // Récupère les données de la ligne courante.
        sigmaDebit += _Donnees[i][1];
        espacement = _Donnees[i][2];
        diametre = _Donnees[i][3];
        longueur = _Donnees[i][4];
        hauteur = _Donnees[i][5];
        // Calcule l'aire du tuyau.
        aireTuyau = (M_PI * pow((diametre / 1000) / 2, 2));

        // Calcule le débit en m3/s.
        debitM3 = sigmaDebit / 3600.0 / 1000.0;

        // Calcule la vitesse.
        vitesse = debitM3 / aireTuyau;

        // Convertit le débit en l/s.
        float sigmaDebitLs = sigmaDebit / 3600.0;

        // Calcule la perte de charge.
        perteCharge = k * pow(sigmaDebitLs, a) * pow(diametre, b) * longueur;

        // Calcule la hauteur piezométrique.
        piezo = perteCharge + hauteur;

        // Ajoute les données calculées au vecteur.
        _Donnees[i][6] = perteCharge;
        _Donnees[i][7] = piezo;

        // Calcule les cumuls pour chaque ligne de données.
        if (i > 0) {
            _Donnees[i][8] = _Donnees[i - 1][8] + perteCharge;
            _Donnees[i][9] = _Donnees[i - 1][9] + piezo;
        } else {
            _Donnees[i][8] = perteCharge;
            _Donnees[i][9] = piezo;
        }

        sigmaPiezo += piezo;
        sigmaPerte += perteCharge;
        sigmaLongueur += longueur;
        sigmaHauteur += hauteur;
    }

// Affiche les résultats dans les cases correspondantes en arrondissant à deux chiffres après la virgule.
    CumulLongueur->setText(QString::number(sigmaLongueur, 'f', 2));
    CumulLongueur->setAlignment(Qt::AlignCenter);
    Cumulhauteur->setText(QString::number(sigmaHauteur, 'f', 2));
    Cumulhauteur->setAlignment(Qt::AlignCenter);
    CumulPerte->setText(QString::number(sigmaPerte, 'f', 2));
    CumulPerte->setAlignment(Qt::AlignCenter);
    CumulPiezo->setText(QString::number(sigmaPiezo, 'f', 2));
    CumulPiezo->setAlignment(Qt::AlignCenter);

    RafraichirTableau();
}

void gag::clear(){
    // Supprime les widgets existants dans le layout de la scrollArea.
    QLayoutItem *item;
    while ((item = scrollAreaLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void gag::RafraichirTableau() {
    clear();

    // Iterate through the vector and add the data to the scrollArea.
    for (int i = 0; i < _Donnees.size(); ++i) {
        for (int j = 0; j < _Donnees[i].size(); ++j) {
            QLineEdit *value;
            if (j == 0) {
                value = new QLineEdit(QString::number(static_cast<int>(_Donnees[i][j])));
            } else {
                value = new QLineEdit(QString::number(_Donnees[i][j], 'f', 2));
            }
            value->setReadOnly(true);
            value->setAlignment(Qt::AlignCenter);
            value->setFixedHeight(40); // Set the fixed height of the line.
            value->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            scrollAreaLayout->addWidget(value, i + 1, j, Qt::AlignTop);
        }
    }
    scrollAreaLayout->setVerticalSpacing(15);
    scrollAreaLayout->setAlignment(Qt::AlignTop);
}


void gag::keyPressEvent(QKeyEvent *event) {
    // Vérifie si la touche Shift est enfoncée et si la touche Entrée est également enfoncée.
    if (event->modifiers() & Qt::ShiftModifier && (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)) {
        // Appelle la fonction calcul().
        calcul();
    } else if (event->key() == Qt::Key_R) {
        recopiederniereligne();
    } else if (event->key() == Qt::Key_M) {
        showUpdateDialog();
    } else if (event->key() == Qt::Key_Z) {
        enleverLigne();
    } else if (event->key() == Qt::Key_E) {
        clear();
    } else if (event->key() == Qt::Key_Control) {
        focusPreviousInput();
    }
}

void gag::recopiederniereligne() { // Fonction déclenché par la touche 'R' qui permet de recopier la derniere ligne entrée

    int taille =_Donnees.size();
    std::vector<float> lastline = _Donnees[taille-1]; // Pour avoir la derniere ligne du vecteur
    std::vector<float> recopie(11, 0.0f);

    recopie[0] = lastline[0]+1; // Numéro
    recopie[1] = lastline[1];   // Debit
    recopie[2] = lastline[2];   // Espacement
    recopie[3] = lastline[3];   // Diametre
    recopie[4] = lastline[4];   // Longueur
    recopie[5] = lastline[5];   // Hauteur

    _Donnees.push_back(recopie);
    AjoutLigne();
}

// Ouvre une boîte de dialogue permettant à l'utilisateur de modifier les données d'une ligne dans le tableau
void gag::showUpdateDialog() {
    // Crée une nouvelle fenêtre de dialogue en tant que sous-fenêtre de la fenêtre principale de l'application
    QDialog *updateDialog = new QDialog(this);
    // Définit le titre de la fenêtre de dialogue
    updateDialog->setWindowTitle("Modifier ligne");

    // Crée un formulaire dans la fenêtre de dialogue pour saisir les nouvelles données de la ligne
    QFormLayout *formLayout = new QFormLayout(updateDialog);

    // Ajoute un champ pour entrer le numéro de ligne à modifier
    QLineEdit *rowNumberLineEdit = new QLineEdit(updateDialog);
    rowNumberLineEdit->setValidator(new QIntValidator(0, _Donnees.size() - 1,updateDialog)); // Permet de limiter la saisie à un nombre entier valide
    formLayout->addRow("Ligne :", rowNumberLineEdit);

    // Ajoute un champ pour entrer le nouveau débit de la ligne
    QLineEdit *debitLineEdit = new QLineEdit(updateDialog);
    formLayout->addRow("Debit:", debitLineEdit);

    // Ajoute un champ pour entrer le nouveau débit de la ligne
    QLineEdit *espacementLineEdit = new QLineEdit(updateDialog);
    formLayout->addRow("Espacement:", espacementLineEdit);

    // Ajoute un champ pour entrer le nouveau diamètre de la ligne
    QLineEdit *diameterLineEdit = new QLineEdit(updateDialog);
    formLayout->addRow("Diametre :", diameterLineEdit);

    // Ajoute un champ pour entrer la nouvelle longueur de la ligne
    QLineEdit *lengthLineEdit = new QLineEdit(updateDialog);
    formLayout->addRow("Longueur :", lengthLineEdit);

    // Ajoute un champ pour entrer la nouvelle hauteur de la ligne
    QLineEdit *heightLineEdit = new QLineEdit(updateDialog);
    formLayout->addRow("Hauteur :", heightLineEdit);

    // Ajoute un bouton pour valider les nouvelles données et fermer la fenêtre de dialogue
    QPushButton *updateButton = new QPushButton("Modifier", updateDialog);
    formLayout->addWidget(updateButton);

    // Fonction qui permet de définir le comportement à adopter lorsque l'utilisateur appuie sur la touche "Entrée" dans un champ de saisie
    auto handleEnterKeyPress = [](QLineEdit *current, QLineEdit *next, std::function<void()> lastAction = nullptr) {
        QObject::connect(current, &QLineEdit::returnPressed, [current, next, lastAction]() {
            // Si le champ en cours de saisie est rempli et que le champ suivant (s'il y en a un) est vide, déplace le curseur vers le champ suivant
            if (!current->text().isEmpty() && (next == nullptr || next->text().isEmpty())) {
                if (next) {
                    next->setFocus();
                } else if (lastAction) {
                    lastAction();
                }
            }
        });
    };

    // Fonction qui met à jour les données de la ligne avec les nouvelles données saisies par l'utilisateur et ferme la fenêtre de dialogue
    auto updateDataAndClose = [this, rowNumberLineEdit, debitLineEdit,espacementLineEdit, diameterLineEdit, lengthLineEdit, heightLineEdit, updateDialog]() {
        // Récupère
        // Récupère les nouvelles données saisies par l'utilisateur
        int rowNumber = rowNumberLineEdit->text().toInt();
        float debit = debitLineEdit->text().toFloat();
        float espacement = espacementLineEdit->text().toFloat();
        float diameter = diameterLineEdit->text().toFloat();
        float length = lengthLineEdit->text().toFloat();
        float height = heightLineEdit->text().toFloat();

        // Met à jour les données de la ligne avec les nouvelles données saisies
        updateData(rowNumber, debit, espacement, diameter, length, height);
        // Ferme la fenêtre de dialogue
        updateDialog->close();
    };

    // Associe la fonction handleEnterKeyPress aux champs de saisie pour gérer les appuis sur la touche "Entrée"
    handleEnterKeyPress(rowNumberLineEdit, debitLineEdit);
    handleEnterKeyPress(debitLineEdit,espacementLineEdit);
    handleEnterKeyPress(espacementLineEdit, diameterLineEdit);
    handleEnterKeyPress(diameterLineEdit, lengthLineEdit);
    handleEnterKeyPress(lengthLineEdit, heightLineEdit);
    handleEnterKeyPress(heightLineEdit, nullptr, updateDataAndClose); // Le dernier champ n'a pas de champ suivant, donc next est nul




    // Associe la fonction updateDataAndClose au bouton "Update" pour mettre à jour les données de la ligne et fermer la fenêtre de dialogue lorsque l'utilisateur clique sur le bouton
    connect(updateButton, &QPushButton::clicked, updateDataAndClose);

    // Ajoute un raccourci clavier pour valider les nouvelles données et fermer la fenêtre de dialogue lorsque l'utilisateur appuie sur la touche "Entrée"
    QShortcut *enterShortcut = new QShortcut(QKeySequence(Qt::Key_Enter), updateDialog);
    QShortcut *returnShortcut = new QShortcut(QKeySequence(Qt::Key_Return), updateDialog);
    connect(enterShortcut, &QShortcut::activated, updateDataAndClose);
    connect(returnShortcut, &QShortcut::activated, updateDataAndClose);

    // Définit le layout du formulaire comme layout de la fenêtre de dialogue et affiche la fenêtre de dialogue modale
    updateDialog->setLayout(formLayout);
    updateDialog->exec();
}

// La fonction "updateData" prend en entrée un numéro de ligne, un débit, un diamètre, une longueur et une hauteur,
// puis met à jour les données de la ligne correspondante dans un tableau.
void gag::updateData(int numeroLigne, float debit,float espacement, float diametre, float longueur, float hauteur) {

    // Vérifie si le numéro de ligne est valide (c'est-à-dire s'il se trouve dans la plage d'index des données).
    if (numeroLigne >= 0 && numeroLigne < _Donnees.size()) {
        // Décrémente le numéro de ligne de 1 pour correspondre à l'indice de tableau (qui commence à 0).
        numeroLigne -= 1;

        // Met à jour les données de la ligne avec les nouvelles valeurs fournies.
        _Donnees[numeroLigne][1] = debit;
        _Donnees[numeroLigne][2] = espacement;
        _Donnees[numeroLigne][3] = diametre;
        _Donnees[numeroLigne][4] = longueur;
        _Donnees[numeroLigne][5] = hauteur;

        // Recalculer et rafraîchir le tableau.
        calcul();
        RafraichirTableau();
    }
}


void gag::enleverLigne() {
    // Crée une nouvelle fenêtre de dialogue pour demander le numéro de la ligne à supprimer
    QDialog *supprimerDialog = new QDialog(this);
    supprimerDialog->setWindowTitle("Supprimer une ligne");
    supprimerDialog->setFixedSize(300, 100);

    // Ajoute un label et un champ de saisie pour entrer le numéro de la ligne à supprimer
    QLabel *numeroLigneLabel = new QLabel("Numéro de ligne :", supprimerDialog);
    QLineEdit *numeroLigneLineEdit = new QLineEdit(supprimerDialog);
    numeroLigneLineEdit->setValidator(new QIntValidator(1, _Donnees.size(), supprimerDialog)); // Permet de limiter la saisie à un nombre entier valide
    numeroLigneLineEdit->setFixedWidth(50);

    QPushButton *supprimerButton = new QPushButton("Supprimer", supprimerDialog);

    // Crée un slot pour gérer la suppression de la ligne
    auto supprimerLigneSlot = [this, numeroLigneLineEdit, supprimerDialog]() {
        int numeroLigne = numeroLigneLineEdit->text().toInt() - 1;
        if (numeroLigne >= 0 && numeroLigne < _Donnees.size()) {
            _Donnees.erase(_Donnees.begin() + numeroLigne); // Supprime la ligne du tableau
            // Réaffecte les numéros de ligne à partir de la ligne supprimée
            for (int i = numeroLigne; i < _Donnees.size(); ++i) {
                _Donnees[i][0] = i + 1;
            }
            RafraichirTableau(); // Actualise l'affichage du tableau
        }
        supprimerDialog->close();
    };

    // Connecte les signaux aux slots
    connect(supprimerButton, &QPushButton::clicked, supprimerLigneSlot);
    connect(numeroLigneLineEdit, &QLineEdit::returnPressed, supprimerLigneSlot);


    // Ajoute un layout à la fenêtre de dialogue
    QVBoxLayout *layout = new QVBoxLayout(supprimerDialog);
    layout->addWidget(numeroLigneLabel);
    layout->addWidget(numeroLigneLineEdit);
    layout->addWidget(supprimerButton);
    layout->setAlignment(Qt::AlignCenter);

    // Affiche la fenêtre de dialogue
    supprimerDialog->exec();

    calcul();
    RafraichirTableau();
}
