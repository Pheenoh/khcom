.syntax unified
	.align 2, 0
	.global func_080543B4
	.thumb
	.thumb_func
	.type func_080543B4, %function
func_080543B4: @ 080543B4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r3, #0x00
	movs r0, #0xE2
	lsls r0, r0, #0x01
	adds r4, r7, r0
	adds r5, r4, #0x0
	movs r6, #0x02
_080543C6:
	strb r3, [r4, #0x01]
	strb r3, [r4, #0x00]
	movs r1, #0xD2
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r1, _080543F0 @ =0x09EDB6E0
	adds r2, r5, #0x0
	str r3, [sp, #0x000]
	bl TaskCreate
	adds r4, #0x0C
	adds r5, #0x0C
	subs r6, #0x01
	ldr r3, [sp, #0x000]
	cmp r6, #0x00
	bge _080543C6
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080543F0: .4byte 0x09EDB6E0
.syntax divided
