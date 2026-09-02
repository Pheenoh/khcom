.syntax unified
	.align 2, 0
	.global func_080A1554
	.thumb
	.thumb_func
	.type func_080A1554, %function
func_080A1554: @ 080A1554
	push {r4, r5, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	beq _080A1584
	mov r4, sp
	adds r4, #0x06
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x004
	movs r1, #0x00
	ldsh r0, [r0, r1]
	str r0, [r5, #0x64]
	movs r1, #0x00
	ldsh r0, [r4, r1]
	subs r0, #0x10
	str r0, [r5, #0x68]
_080A1584:
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
