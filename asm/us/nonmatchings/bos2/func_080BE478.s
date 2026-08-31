.syntax unified
	.align 2, 0
	.global func_080BE478
	.thumb
	.thumb_func
	.type func_080BE478, %function
func_080BE478: @ 080BE478
	push {r4, r5, r6, lr}
	adds r2, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, [r2, #0x00]
	ldr r1, [r0, #0x0C]
	ldr r0, _080BE4B8 @ =0xFFFF8000
	cmp r1, r0
	blt _080BE4F4
	asrs r0, r1, #0x08
	adds r1, r0, #0x0
	adds r1, #0x88
	cmp r1, #0x00
	bge _080BE496
	adds r1, #0x07
_080BE496:
	asrs r1, r1, #0x03
	adds r0, r2, #0x0
	adds r0, #0x6A
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0x20
	ble _080BE4C0
	ldr r0, _080BE4BC @ =0x0203B510
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_0800443C
	b _080BE4E6
_080BE4B8: .4byte 0xFFFF8000
_080BE4BC: .4byte 0x0203B510
_080BE4C0:
	ldr r1, _080BE4FC @ =0x09EF280C
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r5, _080BE500 @ =0x0203B510
	movs r2, #0x20
	subs r2, r2, r6
	lsls r4, r2, #0x06
	lsls r2, r2, #0x16
	lsrs r2, r2, #0x10
	adds r1, r5, #0x0
	bl RequestDma3Copy
	adds r4, r4, r5
	lsls r1, r6, #0x16
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_0800443C
_080BE4E6:
	ldr r0, _080BE504 @ =0x0203B500
	ldr r1, [r0, #0x00]
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
_080BE4F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BE4FC: .4byte 0x09EF280C
_080BE500: .4byte 0x0203B510
_080BE504: .4byte 0x0203B500
.syntax divided
