.syntax unified
	.align 2, 0
	.global func_080DB438
	.thumb
	.thumb_func
	.type func_080DB438, %function
func_080DB438: @ 080DB438
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r4, #0x00
_080DB43E:
	lsls r1, r4, #0x02
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB458
	movs r0, #0x01
	b _080DB460
_080DB458:
	adds r4, #0x01
	cmp r4, #0x04
	ble _080DB43E
	movs r0, #0x00
_080DB460:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
