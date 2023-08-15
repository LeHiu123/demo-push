<?php include 'inc/header.php';?>
<?php include 'inc/sidebar.php';?>
<?php include '../classes/loaithuoc.php';  ?>
<?php include '../classes/nhacungcap.php';  ?>
<?php include '../classes/thuoc.php';  ?>
<?php
    // gọi class category
    $th = new thuoc(); 
    if($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['submit'])){
        // LẤY DỮ LIỆU TỪ PHƯƠNG THỨC Ở FORM POST
        $insertthuoc = $th -> insert_thuoc($_POST, $_FILES); // hàm check productName khi submit lên
    }
  ?>
<div class="grid_8">
    <div class="box round first grid">
        <h2>Thêm sản phẩm</h2>
        <?php 
            if(isset($insertthuoc)){
                echo $insertthuoc;
            }
         ?>   
        <div class="block">

         <form action="addthuoc.php" method="post" enctype="multipart/form-data">
            <table class="form">
                <tr>
                    <td>
                        <label>id thuốc</label>
                    </td>
                    <td>
                        <input name="idthuoc" type="text" placeholder="Nhập mã thuốc" class="medium" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Tên thuốc</label>
                    </td>
                    <td>
                        <input name="tenthuoc" type="text" placeholder="Nhập tên thuốc" class="medium" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Danh mục sản phẩm</label>
                    </td>
                    <td>
                        <select id="select" name="loaithuoc">
                            <option>Chọn loại thuốc</option>
                            <?php 
                            $loaithuoc = new loaithuoc();
                            $dsloaithuoc = $loaithuoc->xem_dsloaithuoc();
                            if($dsloaithuoc){
                                while ($result = $dsloaithuoc->fetch_assoc()){
                            
                             ?>
                            <option value=" <?php echo $result['idloaithuoc'] ?> "> <?php echo $result['tenloaithuoc'] ?> </option>
                            
                            <?php 
                            }
                             }
                             ?>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Danh mục nhà cung cấp</label>
                    </td>
                    <td>
                        <select id="select" name="nhacungcap">
                            <option>Chọn nhà cung cấp</option>
                            <?php 
                            $ncc = new ncc();
                            $dsncc = $ncc->xem_dsnhacungcap();
                            if($dsncc){
                                while ($result = $dsncc->fetch_assoc()){
                            
                             ?>
                            <option value=" <?php echo $result['idnhacungcap'] ?> "> <?php echo $result['tennhacungcap'] ?> </option>
                            
                            <?php 
                            }
                             }
                             ?>
                        </select>
                    </td>
                </tr>
                
                 <tr>
                    <td style="vertical-align: top; padding-top: 9px;">
                        <label>Mô tả</label>
                    </td>
                    <td>
                        <textarea name="mota" class="tinymce"></textarea>
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Giá</label>
                    </td>
                    <td>
                        <input name="giaban" type="text" placeholder="Nhập giá..." class="medium" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Ngày sản xuất</label>
                    </td>
                    <td>
                        <input name="ngaysanxuat" type="date" placeholder="Nhập ngày sản xuất" class="medium" />
                    </td>
                </tr>
                <tr>
                    <td>
                        <label>Tải ảnh</label>
                    </td>
                    <td>
                        <input name="image" type="file" />
                    </td>
                </tr>
                

                <tr>
                    <td></td>
                    <td>
                        <input type="submit" name="submit" Value="Lưu lại" />
                    </td>
                </tr>
            </table>
            </form>
        </div>
    </div>
</div>
<!-- Load TinyMCE -->
<script src="js/tiny-mce/jquery.tinymce.js" type="text/javascript"></script>
<script type="text/javascript">
    $(document).ready(function () {
        setupTinyMCE();
        setDatePicker('date-picker');
        $('input[type="checkbox"]').fancybutton();
        $('input[type="radio"]').fancybutton();
    });
</script>
<!-- Load TinyMCE -->
<?php include 'inc/footer.php';?>


