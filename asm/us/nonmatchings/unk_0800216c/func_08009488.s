.syntax unified
	.align 2, 0
	.global func_08009488
	.thumb
	.thumb_func
	.type func_08009488, %function
func_08009488: @ 08009488
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #0x83
	lsls r0, r0, #0x03
	mov r8, r0
	bl func_08000918
	adds r6, r0, #0x0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x05
	adds r0, r0, r4
	lsls r0, r0, #0x02
	subs r0, r0, r4
	lsls r0, r0, #0x04
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r1, r5, #0x05
	adds r1, r1, r5
	lsls r1, r1, #0x02
	subs r1, r1, r5
	lsls r1, r1, #0x03
	ldr r2, _080094E8 @ =0x0E001EC0
	adds r1, r1, r2
	adds r0, r0, r1
	adds r1, r6, #0x0
	adds r2, r6, #0x0
	mov r3, r8
	bl func_08008AD8
	adds r4, r0, #0x0
	adds r0, r6, #0x0
	bl func_080009C4
	adds r0, r4, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080094E8: .4byte 0x0E001EC0
.syntax divided
