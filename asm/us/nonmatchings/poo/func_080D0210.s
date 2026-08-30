.syntax unified
	.align 2, 0
	.global func_080D0210
	.thumb
	.thumb_func
	.type func_080D0210, %function
func_080D0210: @ 080D0210
	push {r4, lr}
	ldr r2, _080D0240 @ =0x02034E20
	ldr r3, [r2, #0x00]
	ldr r2, [r3, #0x1C]
	subs r4, r0, r2
	ldr r0, [r3, #0x20]
	subs r2, r1, r0
	movs r0, #0xF4
	lsls r0, r0, #0x06
	adds r1, r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r1, r0
	bhi _080D023A
	ldr r0, _080D0244 @ =0xFFFFE100
	cmp r2, r0
	blt _080D023A
	movs r0, #0xE0
	lsls r0, r0, #0x06
	cmp r2, r0
	ble _080D0248
_080D023A:
	movs r0, #0x00
	b _080D0288
	.byte 0x00, 0x00
_080D0240: .4byte 0x02034E20
_080D0244: .4byte 0xFFFFE100
_080D0248:
	ldr r0, _080D0258 @ =0xFFFFEF00
	cmp r4, r0
	bge _080D0260
	ldr r0, _080D025C @ =0x000002FF
	cmp r2, r0
	bgt _080D0260
	movs r0, #0x53
	b _080D0288
_080D0258: .4byte 0xFFFFEF00
_080D025C: .4byte 0x000002FF
_080D0260:
	movs r0, #0xB8
	lsls r0, r0, #0x05
	cmp r4, r0
	ble _080D0274
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r2, r0
	ble _080D0274
	movs r0, #0xD3
	b _080D0288
_080D0274:
	negs r0, r4
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	adds r0, r0, r2
	cmp r0, #0x00
	bgt _080D0286
	movs r0, #0xAD
	b _080D0288
_080D0286:
	movs r0, #0x2D
_080D0288:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
