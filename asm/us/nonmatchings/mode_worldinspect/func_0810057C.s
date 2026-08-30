.syntax unified
	.align 2, 0
	.global func_0810057C
	.thumb
	.thumb_func
	.type func_0810057C, %function
func_0810057C: @ 0810057C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r2, #0x0
	ldr r4, [sp, #0x018]
	ldr r6, [sp, #0x01C]
	ldr r2, [sp, #0x020]
	ldr r5, [sp, #0x024]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0B
	adds r3, r3, r4
	lsls r3, r3, #0x01
	adds r7, r7, r3
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x0B
	adds r2, r2, r5
	lsls r2, r2, #0x01
	adds r6, r6, r2
	movs r3, #0x00
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r3, r1
	bge _081005FC
	lsls r0, r0, #0x10
	mov r8, r0
	asrs r0, r0, #0x10
	mov r12, r0
	movs r0, #0x20
	mov r2, r12
	subs r0, r0, r2
	lsls r5, r0, #0x01
_081005C6:
	movs r2, #0x00
	lsls r4, r3, #0x10
	cmp r2, r12
	bge _081005EA
	mov r0, r8
	asrs r3, r0, #0x10
_081005D2:
	ldrh r0, [r7, #0x00]
	strh r0, [r6, #0x00]
	adds r7, #0x02
	adds r6, #0x02
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	blt _081005D2
_081005EA:
	adds r7, r7, r5
	adds r6, r6, r5
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r4, r2
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	blt _081005C6
_081005FC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
