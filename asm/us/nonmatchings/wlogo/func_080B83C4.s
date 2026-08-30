.syntax unified
	.align 2, 0
	.global func_080B83C4
	.thumb
	.thumb_func
	.type func_080B83C4, %function
func_080B83C4: @ 080B83C4
	push {r4, lr}
	adds r3, r0, #0x0
	ldr r0, _080B840C @ =0x00000484
	adds r1, r3, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	movs r4, #0x00
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	ble _080B8404
	strh r4, [r1, #0x00]
	ldr r0, _080B8410 @ =0x00000482
	adds r2, r3, r0
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0A
	ble _080B83F2
	strh r4, [r2, #0x00]
_080B83F2:
	ldr r1, _080B8414 @ =0x09EF1D58
	movs r4, #0x00
	ldsh r0, [r2, r4]
	adds r0, r0, r1
	ldrb r1, [r0, #0x00]
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r0, r3, r2
	strb r1, [r0, #0x00]
_080B8404:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B840C: .4byte 0x00000484
_080B8410: .4byte 0x00000482
_080B8414: .4byte 0x09EF1D58
.syntax divided
