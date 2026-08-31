.syntax unified
	.align 2, 0
	.global task_bos_pc_acd_2
	.thumb
	.thumb_func
	.type task_bos_pc_acd_2, %function
task_bos_pc_acd_2: @ 0810C03C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r0, _0810C0E8 @ =0x02039B84
	mov r9, r0
	ldr r4, [r0, #0x00]
	ldr r3, [r4, #0x7C]
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _0810C0EC @ =0xFDFFFFFF
	ands r0, r2
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	movs r6, #0x00
	mov r10, r6
	ldr r2, [r7, #0x1C]
	ldrb r0, [r2, #0x05]
	cmp r0, #0x01
	bne _0810C082
	ldr r0, _0810C0F0 @ =0x02039DC8
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x68
	movs r5, #0x00
	ldsh r1, [r1, r5]
	lsls r6, r1, #0x08
	adds r0, #0x6A
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	mov r10, r0
_0810C082:
	ldr r0, [r3, #0x04]
	str r0, [r7, #0x0C]
	ldr r0, [r3, #0x08]
	ldr r5, _0810C0F4 @ =0xFFFFFC00
	adds r0, r0, r5
	str r0, [r7, #0x10]
	movs r0, #0x00
	mov r8, r0
	str r0, [r7, #0x14]
	ldrb r0, [r2, #0x04]
	cmp r0, #0x01
	bne _0810C0FC
	ldr r4, _0810C0F8 @ =0x09EFAB68
	adds r0, r7, #0x0
	adds r0, #0x20
	bl func_08005B38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, #0x14
	adds r0, r0, r4
	ldr r5, [r0, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0810C0C6
	b _0810C1B8
_0810C0C6:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x0C]
	subs r2, r2, r6
	movs r6, #0xC0
	lsls r6, r6, #0x03
	adds r2, r2, r6
	ldr r3, [r7, #0x10]
	mov r0, r10
	subs r3, r3, r0
	mov r1, r8
	str r1, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	b _0810C1D8
_0810C0E8: .4byte 0x02039B84
_0810C0EC: .4byte 0xFDFFFFFF
_0810C0F0: .4byte 0x02039DC8
_0810C0F4: .4byte 0xFFFFFC00
_0810C0F8: .4byte 0x09EFAB68
_0810C0FC:
	ldr r0, [r3, #0x0C]
	cmp r0, #0x00
	bge _0810C104
	b _0810C288
_0810C104:
	ldr r3, [r4, #0x68]
	ldr r4, [r4, #0x6C]
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C12C
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C12C
	b _0810C288
_0810C12C:
	adds r5, r7, #0x0
	adds r5, #0x20
	adds r0, r5, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bne _0810C220
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r4, [r0, #0x7C]
	ldr r2, [r4, #0x34]
	ldr r3, [r4, #0x38]
	ldr r1, _0810C1B0 @ =0x00000000
	ldr r0, _0810C1AC @ =0x02000000
	orrs r2, r0
	str r2, [r4, #0x34]
	str r3, [r4, #0x38]
	movs r4, #0x80
	adds r0, r2, #0x0
	ands r0, r4
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C162
	b _0810C288
_0810C162:
	ldr r4, _0810C1B4 @ =0x09EFAB68
	adds r0, r5, #0x0
	bl func_08005B38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, #0x14
	adds r0, r0, r4
	ldr r5, [r0, #0x00]
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C1B8
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x0C]
	subs r2, r2, r6
	movs r6, #0xC0
	lsls r6, r6, #0x03
	adds r2, r2, r6
	ldr r3, [r7, #0x10]
	mov r0, r10
	subs r3, r3, r0
	mov r1, r8
	str r1, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	b _0810C1D8
_0810C1AC: .4byte 0x02000000
_0810C1B0: .4byte 0x00000000
_0810C1B4: .4byte 0x09EFAB68
_0810C1B8:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x0C]
	subs r2, r2, r6
	movs r6, #0x80
	lsls r6, r6, #0x02
	adds r2, r2, r6
	ldr r3, [r7, #0x10]
	mov r0, r10
	subs r3, r3, r0
	mov r1, r8
	str r1, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
_0810C1D8:
	adds r6, r4, #0x0
	ldr r0, [r7, #0x10]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r4, [r1, r2]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x08]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r2, [r7, #0x10]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r6, _0810C21C @ =0xFFFFEFFC
	adds r0, r6, #0x0
	subs r0, r0, r2
	movs r2, #0x03
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl DrawSprite
	b _0810C288
	.byte 0x00, 0x00
_0810C21C: .4byte 0xFFFFEFFC
_0810C220:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r7, #0x0C]
	subs r2, r2, r6
	ldr r3, [r7, #0x10]
	mov r0, r10
	subs r3, r3, r0
	mov r1, r8
	str r1, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	adds r0, r5, #0x0
	bl AnimGetGfx
	adds r6, r0, #0x0
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r5, [r1, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r7, #0x04]
	ldr r2, [r7, #0x08]
	str r2, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r4, _0810C298 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r2, r6, #0x0
	bl DrawSprite
_0810C288:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0810C298: .4byte 0xFFFFEFFC
.syntax divided
