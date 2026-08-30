.syntax unified
	.align 2, 0
	.global task_smn_tinkeff_1
	.thumb
	.thumb_func
	.type task_smn_tinkeff_1, %function
task_smn_tinkeff_1: @ 0804305C
	push {r4, lr}
	ldr r1, [r0, #0x28]
	ldr r2, [r0, #0x2C]
	adds r1, r1, r2
	str r1, [r0, #0x28]
	adds r4, r0, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08043080
	adds r0, r4, #0x0
	bl func_08005A64
	movs r0, #0x01
	b _08043082
_08043080:
	movs r0, #0x00
_08043082:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
