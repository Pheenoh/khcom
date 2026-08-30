.syntax unified
	.align 2, 0
	.global func_0810063C
	.thumb
	.thumb_func
	.type func_0810063C, %function
func_0810063C: @ 0810063C
	push {lr}
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0x00
	ble _08100668
	ldr r1, _08100660 @ =0x09EF9488
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r1, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r1, _08100664 @ =0x020356E0
	bl func_08065B6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0810066A
_08100660: .4byte 0x09EF9488
_08100664: .4byte 0x020356E0
_08100668:
	movs r0, #0x00
_0810066A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
