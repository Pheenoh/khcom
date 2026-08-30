.syntax unified
	.align 2, 0
	.global task_poo_eeyoretail_1
	.thumb
	.thumb_func
	.type task_poo_eeyoretail_1, %function
task_poo_eeyoretail_1: @ 080CF900
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_080C9D84
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CF958
	ldr r5, _080CF960 @ =0x02034E18
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080CF950
	adds r0, r4, #0x0
	adds r0, #0x0C
	ldr r1, _080CF964 @ =0x0007FD00
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x10
	ldr r1, _080CF968 @ =0x00049300
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x20
	ldrh r2, [r5, #0x00]
	movs r1, #0x00
	bl func_080058FC
	ldr r2, [r4, #0x20]
	negs r2, r2
	str r2, [r4, #0x14]
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x10]
	adds r1, r1, r2
	bl func_080C9FA8
_080CF950:
	adds r0, r4, #0x0
	adds r0, #0x24
	bl func_08000EA4
_080CF958:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_080CF960: .4byte 0x02034E18
_080CF964: .4byte 0x0007FD00
_080CF968: .4byte 0x00049300
.syntax divided
