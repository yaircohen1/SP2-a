# תכנות מערכות 2 מטלה מספר 1
הפעלה:
קימפול התוכנית.
make:
הרצת פונקציית main.
./demo:
קמפול והרצת הטסטים.
make test:
הרצת הטסטים בלבד.
./test: 


מאפייני הגרף:
גרף מכוון: זהו גרף עם מטריצה לא סימטרית. חיבור בין U ל-V לא נחשב כמעגל, בעוד שחיבור מכוון מ-U ל-V ומ-V ל-U נחשב כמעגל רק אם משקלי הצלעות שונים.
גרף לא מכוון: זהו גרף עם מטריצה סימטרית ולכן מס' הצלעות הוא לפי מס' הקודקים במטריצה חלקי 2.
מעגל: חיבור מ-U לV וכן הלאה עד לקודקוד U בחזרה.
מעגל שלילי: סכום צלעות של המעגל קטן מ-0.

Graph.cpp
מחלקה המייצגת גרף, בונה אותו, מאתחלת את המשתנים ומדפיסה אותו.

פונקציות:
Graph::Graph():
מאתחלת את הגרף עם ערכים ברירת מחדל:

Matrix(): מטריצת שכנויות המייצגת את הגרף.
numOfVertices(0): מספר הקודקודים התחלתי.
numEdges(0): מספר הצלעות התחלתי.
isDirected(false): מאתחלת את תכונת הגרף כלא מכוון כברירת מחדל.
isWeighted(false): מאתחלת את הגרף כלא ממושקל.
isNegative(false): מאתחלת את צלעות המשקלים כלא שליליים.

void Graph::loadGraph(const vector<vector<int>>& matrix):
טוענת את הגרף ממטריצת השכנויות שמועברת כפרמטר ומעדכנת את מספר הקודקודים, צלעות ושאר תכונות הגרף בהתאם.

void Graph::printGraph():
מדפיסה את תכונות הגרף במלואם.

פונקציות גטרים לתכונות הגרף המוגדרות כפרטיות:
const vector<vector<int>>& Graph::getMatrix() const:
size_t Graph::getNumV() const:
size_t Graph::getNumE() const:
bool Graph::getIsDirected() const:
bool Graph::getIsWeighted() const: 
bool Graph::getHasNegativeEdges() const:

פירוק הבנאי:
Graph::~Graph()

Algorithms.cpp
מחלקה המייצגת את כל האלגוריתמים הנדרשים, וכן שימוש בפונקציות עזר המוצהרות הקובץ הhpp הנפרד להם וכלולים בקובץ הhpp של האלגוריתמים.

פונקציות:

bool Algorithms::isConnected(Graph& g):
מממשת אלגוריתם BFS מכל קודקוד, ובודקת אם יש קודקוד שלא ניתן להגיע אליו מקודקוד אחר. אם קיים כזה, הגרף אינו קשיר חזק, אחרת הגרף קשיר.

string Algorithms::shortestPath(Graph& g, int start, int end):
פונקציה המקבלת גרף, קודקוד התחלה וקודקוד סיום. במידה ויש בגרף צלעות עם משקלים שליליים, נעזרת בפונקציית עזר shortestPathBellmanFord ממחלקת PathWeight לחישוב המסלול הקצר. אם אין משקלים שליליים, משתמשת בפונקציית עזר shortestPathDijkstra ממחלקת PathWeight. במידה והצלעות לא ממושקלות, נעזר בפונקצית עזר shortestPathBFS ממחלקת PathNoWeight ומחזירה את המסלול הקצר ביותר אם קיים, אחרת מחזירה -1.

string Algorithms::isContainsCycle(Graph& g):
מריצה את פונקציית העזר DFScycle ממחלקת PathNoWeight על כל קודקוד כדי לבדוק אם הגרף מכיל מעגל.
במידה וכן, מדפיס את המעגל. אחרת מדפיס "0".

string Algorithms::isBipartite(Graph& g):
פונקציה הבודקת אם הגרף דו-צדדי בעזרת אלגוריתם המדמה BFS. צובעת את הקודקודים בשני צבעים, ובודקת אם יש שכנים עם אותו צבע.

string Algorithms::negativeCycle(Graph& g):
פונקציה המשתמשת בפונקציית עזר shortestPathBellmanFord ממחלקת PathWeight להרצת האלגוריתם ע"מ למצוא מעגל שלילי באמצעות משתנה בוליאני שנרחיב עליו בהמשך.

PathNoWeight.cpp
מחלקה המיישמת אלגוריתמים למציאת מסלולים הכי קצרים כאשר אין לצלעות הגרף משקל כגון: BFS וDFS.

פונקציות:
 string PathNoWeight::shortestPathBFS(const Graph& g, size_t start, size_t end):
פונקציה המדפיסה את המסלול הכי קצר באמצעות אלגוריתם BFS המשתמש בתור וצביעת קודקודים.
הפונקציה תחזיר את המסלול הכי קצר כstring. במידה ולא קיים מסלול תחזיר "-1". הפונקציה מקבלת קריאה כאשר נשתמש בפונקציית string Algorithms::isContainsCycle(Graph& g).

 string PathNoWeight::DFSvisit(const Graph& g, size_t v, vector<int> &color,vector<int> &parent):
פונקציית עזר לפונקציית DFScycle שנמצאת גם היא במחלקה ומבצעת לה קריאה. הפונקצעה מתבצעת באופן רקורסיבי על כל השכנים של קודקוד מסויים. כאשר מזהה קודקוד בצבע אפור, אזי מזהה צלע Backend ולכן זה מרמז על כך שקיים מעגל בגרף. מחזירה את מסלול המעגל במידה וקיים.
string PathNoWeight::DFScycle(const Graph& g)
פונקציה המדפיסה את קודקודי המעגל הקיים בגרף. נעזר באמצעות אלגוריתם DFS ובתוכו קריאה לפונקצית עזר הרקורסיבית DFSvisit.

PathWeight.cpp
מחלקה המיישמת אלגוריתמים למציאת מסלול הכי קל בגרף ממושקל  כגון: BellmanFord לגרף עם צלעות שליליות ו - Dijkstra לגרף עם צלעות עם משקלים לא שליליים.

פונקציות:
string PathWeight::shortestPathDijkstra(const Graph& g, size_t start, size_t end):
שימוש באלגוריתם דייקסטרה למציאת המסלול הקצר ביותר בין קודקוד אחד לאחר, במידה וקיים ידפיס את המסלול. אחרת מחזיר "-1".

string PathWeight::shortestPathBellmanFord(const Graph& g, size_t start, size_t end, bool flag):
פונקציה למציאת מסלול הקל ביותר בגרם עם צלעות שליליות מקודקוד start לקודקוד end. בנוסף גם מקבל דגל בוליאני. במידה והדגל הבוליאני שלילי אז נקרא מהפונקציה  string Algorithms::shortestPath ולכן 
ידפיס רק את המסלול הקל ביותר, במידה ונתקל במעגל שלילי יחזיר הדפסת שגיאה. אחרת, והמשתנה הוא חיובי אזי הפונקצייה נקראת מפונקציית string Algorithms::negativeCycle(Graph& g) ובכך יבצע חיפוש באותה פונקציה למעגלים שליליים. במידה וקיים, יחזיר את מסלול המעגל.


