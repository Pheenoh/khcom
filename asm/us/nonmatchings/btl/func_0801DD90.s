.syntax unified
	.align 2, 0
	.global func_0801DD90
	.thumb
	.thumb_func
	.type func_0801DD90, %function
func_0801DD90: @ 0801DD90
	push {lr}
	add sp, #-0x00C
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801DDBA
	add r1, sp, #0x004
	add r2, sp, #0x008
	mov r0, sp
	bl func_080140C0
	ldr r0, [sp, #0x000]
	ldr r1, _0801DDC0 @ =0x02039B84
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x7C]
	ldr r1, [r2, #0x08]
	ldr r2, [r2, #0x0C]
	bl func_0802F284
_0801DDBA:
	add sp, #0x00C
	pop {r0}
	bx r0
_0801DDC0: .4byte 0x02039B84
.syntax divided
