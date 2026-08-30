.syntax unified
	.align 2, 0
	.global task_hum_mahluxia_flw_2
	.thumb
	.thumb_func
	.type task_hum_mahluxia_flw_2, %function
task_hum_mahluxia_flw_2: @ 08057C44
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	adds r6, r0, #0x0
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x30]
	ldr r3, [r4, #0x34]
	ldr r0, [r4, #0x38]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x08]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldr r4, [r4, #0x34]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08057CA0 @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl func_080023E0
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08057CA0: .4byte 0xFFFFEFFC
.syntax divided
