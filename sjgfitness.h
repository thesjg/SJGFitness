#ifndef SJGFITNESS_H
#define SJGFITNESS_H

#include <QtGui/QMainWindow>


class QMenu;
class QAction;
class QWebView;

class SJGFitness : public QMainWindow
{
	Q_OBJECT

public:
	SJGFitness();

signals:
	void filesImporting();
	void filesImported(const QMap<QString, QVariant> &);

private slots:
	void exit();

	void athleteChange();
	void athleteCreate();
	void athleteImport();
	void athleteSettings();

	void toolsImport();
	void toolsExport();

	void helpAbout();

private:
	void createActions();
	void createMenus();
	void createToolbars();
	void createWebView();

	QMenu *fileMenu;
	QMenu *athleteMenu;
	QMenu *deviceMenu;
	QMenu *toolsMenu;
	QMenu *helpMenu;

	// File menu actions
	QAction *fileExitAct;

	// Athlete menu actions
	QAction *athleteChangeAct;
	QAction *athleteCreateAct;
	QAction *athleteImportAct;
	QAction *athleteSettingsAct;

	// Tools menu actions
	QAction *toolsImportAct;
	QAction *toolsExportAct;

	// Help menu actions
	QAction *helpAboutAct;

	QWebView *webView;
};

#endif // SJGFITNESS_H
