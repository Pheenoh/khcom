.syntax unified
	.align 2, 0
	.global func_080C8A50
	.thumb
	.thumb_func
	.type func_080C8A50, %function
func_080C8A50: @ 080C8A50
	push {r4, lr}
	add sp, #-0x020
	mov r12, r0
	mov r1, sp
	ldr r0, _080C8AB4 @ =0x096FC6B0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	movs r3, #0x00
	mov r0, r12
	adds r0, #0x90
	ldr r1, [r0, #0x00]
	ldr r0, [sp, #0x000]
	cmp r1, r0
	bne _080C8A80
	mov r0, r12
	adds r0, #0x94
	ldr r1, [r0, #0x00]
	ldr r0, [sp, #0x004]
	cmp r1, r0
	beq _080C8AA8
_080C8A80:
	adds r3, #0x01
	cmp r3, #0x03
	bhi _080C8AA8
	mov r1, r12
	adds r1, #0x90
	lsls r2, r3, #0x03
	mov r4, sp
	adds r0, r4, r2
	ldr r1, [r1, #0x00]
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _080C8A80
	mov r1, r12
	adds r1, #0x94
	add r0, sp, #0x004
	adds r0, r0, r2
	ldr r1, [r1, #0x00]
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _080C8A80
_080C8AA8:
	adds r0, r3, #0x0
	add sp, #0x020
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080C8AB4: .4byte 0x096FC6B0
.syntax divided
