本系统分为两个独立的Project：PersonCountingLib（主程序）和core_count（核心算法模块）。

PersonCountingLib（主程序）
=========================================================================================================================
完成加密狗验证、佳发公司通信协议实现、获取教室列表和状态、获取图片列表、调用核心算法模块等功能，主要文件：
1. PersonCountingLib.cpp: 主程序，载入配置文件、完成各模块调用和处理（今后还会加入上传到服务器的功能）；
2. SenseLockEncryptor.h， psense4.h, sense4.h:  加密狗验证模块；
3. GeneralHandler.h: 佳发公司底层通信协议实现；
4. ErrorOperator.h, ErrorOperator.cpp: 错误处理模块。


core_count （核心识别算法）
=========================================================================================================================
实现人数统计的核心算法；
1. core_count.cpp: 主程序，完成各模块调用和处理；
2. detect_core.h: 人数统计算法主模块，负责依次调用级联检测器、CNN分类器、和两个后处理模块；
3. post_template_comparator.h: 后处理模块1：负责和现有模板进行匹配，剔除不可能区域检测框；
4. post_template_containing.h: 后处理模块2，负责提出包含关系的检测框；