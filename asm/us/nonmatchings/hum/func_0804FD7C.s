.syntax unified
	.align 2, 0
	.global func_0804FD7C
	.thumb
	.thumb_func
	.type func_0804FD7C, %function
func_0804FD7C: @ 0804FD7C
	push {r4, r5, lr}
	add sp, #-0x020
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x40
	ldr r0, _0804FE18 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x05
	bl __umodsi3
	cmp r0, #0x00
	bne _0804FE0E
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x004]
	adds r0, r5, #0x0
	adds r0, #0xE2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x008]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _0804FE1C @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [sp, #0x000]
	adds r1, r1, r0
	str r1, [sp, #0x000]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r2, _0804FE20 @ =0xFFFFF000
	adds r0, r0, r2
	ldr r1, [sp, #0x004]
	adds r1, r1, r0
	str r1, [sp, #0x004]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x29
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _0804FE20 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [sp, #0x008]
	adds r1, r1, r0
	str r1, [sp, #0x008]
	movs r2, #0xE4
	lsls r2, r2, #0x02
	adds r0, r5, r2
	ldr r1, _0804FE24 @ =0x09EDB788
	mov r2, sp
	bl TaskCreate
_0804FE0E:
	add sp, #0x020
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804FE18: .4byte 0x03007480
_0804FE1C: .4byte 0xFFFFE000
_0804FE20: .4byte 0xFFFFF000
_0804FE24: .4byte 0x09EDB788
.syntax divided
