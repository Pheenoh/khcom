.syntax unified
	.align 2, 0
	.global func_080D6908
	.thumb
	.thumb_func
	.type func_080D6908, %function
func_080D6908: @ 080D6908
	movs r2, #0x00
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r3, _080D6940 @ =0x096FDCC8
	ldr r0, [r3, #0x00]
	cmp r1, r0
	beq _080D6930
_080D6916:
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _080D6938
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _080D6916
_080D6930:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _080D693A
_080D6938:
	movs r2, #0x00
_080D693A:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	bx lr
_080D6940: .4byte 0x096FDCC8
.syntax divided
