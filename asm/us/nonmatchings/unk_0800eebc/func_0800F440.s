.syntax unified
	.align 2, 0
	.global func_0800F440
	.thumb
	.thumb_func
	.type func_0800F440, %function
func_0800F440: @ 0800F440
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r4, r3, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r5, r0, #0x0
	adds r5, #0x40
	add r2, sp, #0x004
	adds r0, r5, #0x0
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	lsls r4, r4, #0x08
	ldr r2, [r5, #0x08]
	ldr r0, [sp, #0x004]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _0800F474
	cmp r1, r4
	bgt _0800F4A2
	b _0800F47A
_0800F474:
	subs r0, r0, r2
	cmp r0, r4
	bgt _0800F4A2
_0800F47A:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F4A6
	lsls r0, r6, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r5, #0x04]
	subs r2, r1, r0
	lsls r1, r7, #0x08
	subs r0, r2, r1
	ldr r3, [sp, #0x000]
	cmp r0, r3
	bgt _0800F4A2
	adds r0, r2, r1
	cmp r0, r3
	bge _0800F4BE
_0800F4A2:
	movs r0, #0x00
	b _0800F4C0
_0800F4A6:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r5, #0x04]
	adds r2, r1, r0
	lsls r1, r7, #0x08
	adds r0, r2, r1
	ldr r3, [sp, #0x000]
	cmp r0, r3
	blt _0800F4A2
	subs r0, r2, r1
	cmp r0, r3
	bgt _0800F4A2
_0800F4BE:
	movs r0, #0x01
_0800F4C0:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
