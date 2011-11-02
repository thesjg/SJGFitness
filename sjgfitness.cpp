#include <QtGui>
#include <QtWebKit>
#include "sjgfitness.h"


SJGFitness::SJGFitness()
{
	createActions();
	createMenus();
	// createToolbars();
	createWebView();
}

void
SJGFitness::createActions()
{
	// File menu actions
	fileExitAct = new QAction(tr("E&xit"), this);
	fileExitAct->setStatusTip(tr(""));
	connect(fileExitAct, SIGNAL(triggered()), this, SLOT(exit()));

	// Athlete menu actions
	athleteChangeAct = new QAction(tr("&Change"), this);
	athleteChangeAct->setStatusTip(tr(""));
	connect(athleteChangeAct, SIGNAL(triggered()), this, SLOT(athleteChange()));

	athleteCreateAct = new QAction(tr("C&reate"), this);
	athleteCreateAct->setStatusTip(tr(""));
	connect(athleteCreateAct, SIGNAL(triggered()), this, SLOT(athleteCreate()));

	athleteImportAct = new QAction(tr("&Import"), this);
	athleteImportAct->setStatusTip(tr(""));
	connect(athleteImportAct, SIGNAL(triggered()), this, SLOT(athleteImport()));

	athleteSettingsAct = new QAction(tr("&Settings"), this);
	athleteSettingsAct->setStatusTip(tr(""));
	connect(athleteSettingsAct, SIGNAL(triggered()), this, SLOT(athleteSettings()));

	// Tools menu actions
	toolsImportAct = new QAction(tr("&Import"), this);
	toolsImportAct->setStatusTip(tr(""));
	connect(toolsImportAct, SIGNAL(triggered()), this, SLOT(toolsImport()));

	toolsExportAct = new QAction(tr("&Export"), this);
	toolsExportAct->setStatusTip(tr(""));
	connect(toolsExportAct, SIGNAL(triggered()), this, SLOT(toolsExport()));

	// Help menu actions
	helpAboutAct = new QAction(tr("&About"), this);
	helpAboutAct->setStatusTip(tr("Information about the SJGFitness application"));
	connect(helpAboutAct, SIGNAL(triggered()), this, SLOT(helpAbout()));
}

void
SJGFitness::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(fileExitAct);

	athleteMenu = menuBar()->addMenu(tr("&Athlete"));
	athleteMenu->addAction(athleteChangeAct);
	athleteMenu->addAction(athleteCreateAct);
	athleteMenu->addAction(athleteImportAct);
	athleteMenu->addAction(athleteSettingsAct);

	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(toolsImportAct);
	toolsMenu->addAction(toolsExportAct);

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(helpAboutAct);
}

void
SJGFitness::createToolbars()
{

}

void
SJGFitness::createWebView()
{
	webView = new QWebView(this);
	webView->page()->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
	webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
	webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
	webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
	webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("SJGFitDesktop"), this);
	webView->load(QUrl("qrc:/calendar.html"));
	setCentralWidget(webView);
}

void
SJGFitness::exit()
{
	close();
}

void
SJGFitness::athleteChange()
{
}

void
SJGFitness::athleteCreate()
{
}

void
SJGFitness::athleteImport()
{
}

void
SJGFitness::athleteSettings()
{
}

void
SJGFitness::toolsImport()
{
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::ExistingFiles);
	dialog.setNameFilter(tr("Fitness Logs (*.tcx *.gpx)"));
	dialog.setViewMode(QFileDialog::Detail);

	QStringList fileNames;
	QMap<QString, QVariant> files;
	if (dialog.exec()) {
		emit filesImporting();
		fileNames = dialog.selectedFiles();
		for (int i = 0; i < fileNames.size(); ++i) {
			QFile file(fileNames.at(i));
			file.open(QIODevice::ReadOnly | QIODevice::Text);
			QVariant fileData(QString(file.readAll()));
			files.insert(fileNames.at(i), fileData);
		}
		emit filesImported(files);
	}
}

void
SJGFitness::toolsExport()
{
}

void
SJGFitness::helpAbout()
{
	QMessageBox::about(this, tr("About SJGFitness"),
		tr(""));
}